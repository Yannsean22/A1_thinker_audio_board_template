#include "globalVar.h"

const char *ES_TAG = "ES8388";
const char *MUSIC_TAG = "MUSIC";

i2s_chan_handle_t tx_handle = NULL;
i2s_chan_handle_t rx_handle = NULL;
extern const uint8_t music_pcm_start[] asm("_binary_output_pcm_start");
extern const uint8_t music_pcm_end[]   asm("_binary_output_pcm_end");
esp_err_t es83188Init(void) {
    audio_hal_codec_config_t es8388_init_cfg = {
        .adc_input = AUDIO_HAL_ADC_INPUT_LINE1,
        .dac_output = AUDIO_HAL_DAC_OUTPUT_ALL,
        .codec_mode = AUDIO_HAL_CODEC_MODE_BOTH,
        .i2s_iface = {
            .mode = AUDIO_HAL_MODE_MASTER,
            .fmt = AUDIO_HAL_I2S_NORMAL,
            .samples = AUDIO_HAL_48K_SAMPLES,
            .bits = AUDIO_HAL_BIT_LENGTH_32BITS
            
        }
        
    };

    if (es8388_init(&es8388_init_cfg) != ESP_OK) {
        ESP_LOGE(ES_TAG, "ES8388 initialization failed!");
        return ESP_FAIL;
    }

    es_module_t es8388_start_cfg = ES_MODULE_ADC_DAC;
    es8388_start(es8388_start_cfg);
    es8388_ctrl_state(AUDIO_HAL_CODEC_MODE_BOTH, AUDIO_HAL_CTRL_START);
    es8388_set_voice_volume(100);
    

    ESP_LOGI(ES_TAG, "ES8388 initialized successfully");
    return ESP_OK;
}

esp_err_t i2sInit(void) {
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);
    chan_cfg.auto_clear = true;

    if (i2s_new_channel(&chan_cfg, &tx_handle, &rx_handle) != ESP_OK) {
        ESP_LOGE(ES_TAG, "Failed to create I2S channel");
        return ESP_FAIL;
    }

    i2s_std_clk_config_t clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(EXAMPLE_SAMPLE_RATE);
    clk_cfg.mclk_multiple = EXAMPLE_MCLK_MULTIPLE;

    i2s_std_config_t std_cfg = {
        .clk_cfg = clk_cfg,
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO),
        .gpio_cfg = {
            .mclk = GPIO_NUM_0,   
            .bclk = GPIO_NUM_27,
            .ws = GPIO_NUM_25,
            .dout = GPIO_NUM_26,
            .din = GPIO_NUM_35,
            .invert_flags = { false, false, false },
        },
        
    };

    // Initialize both TX and RX channels
    if (i2s_channel_init_std_mode(tx_handle, &std_cfg) != ESP_OK ||
        i2s_channel_init_std_mode(rx_handle, &std_cfg) != ESP_OK ||
        i2s_channel_enable(tx_handle) != ESP_OK ||
        i2s_channel_enable(rx_handle) != ESP_OK) {
        ESP_LOGE(ES_TAG, "I2S initialization failed!");
        return ESP_FAIL;
    }

    ESP_LOGI(ES_TAG, "I2S initialized successfully");
    return ESP_OK;
}


void i2s_music_pcm(void *args) {
    esp_err_t ret;
    size_t bytes_write;
    uint8_t *data_ptr = (uint8_t *)music_pcm_start;
    size_t data_size = music_pcm_end - music_pcm_start;

    ESP_ERROR_CHECK(i2s_channel_disable(tx_handle));
    ESP_ERROR_CHECK(i2s_channel_enable(tx_handle));

    while (1) {
        ret = i2s_channel_write(tx_handle, data_ptr, data_size, &bytes_write, portMAX_DELAY);
        if (ret != ESP_OK) {
            ESP_LOGE(MUSIC_TAG, "[music] i2s write failed, %s", esp_err_to_name(ret));
            abort();
        }

        if (bytes_write > 0) {
            ESP_LOGI(MUSIC_TAG, "[music] %d bytes written.", bytes_write);
        }

        // Move pointer forward and loop playback
        data_ptr += bytes_write;
        if (data_ptr >= music_pcm_end) {
            data_ptr = (uint8_t *)music_pcm_start;
        }
    }
    vTaskDelete(NULL);
}



void app_main() {
    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_ERROR_CHECK(es83188Init());
    ESP_ERROR_CHECK(i2sInit());

    ESP_LOGI(ES_TAG, "System initialized. Starting audio...");
    xTaskCreate(i2s_music_pcm, "i2s_music_pcm", 8192, NULL, 5, NULL);
}
