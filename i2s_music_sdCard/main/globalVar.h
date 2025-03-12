#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "sdkconfig.h"
#include "audio_element.h"
#include "audio_pipeline.h"
#include "audio_event_iface.h"
#include "audio_common.h"
#include "fatfs_stream.h"
#include "i2s_stream.h"
#include <board.h>
#ifdef CONFIG_AUDIO_SUPPORT_MP3_DECODER
#include "mp3_decoder.h"
#elif (CONFIG_AUDIO_SUPPORT_AMRNB_DECODER ||    \
        CONFIG_AUDIO_SUPPORT_AMRWB_DECODER)
#include "amr_decoder.h"
#elif CONFIG_AUDIO_SUPPORT_OPUS_DECODER
#include "opus_decoder.h"
#elif CONFIG_AUDIO_SUPPORT_OGG_DECODER
#include "ogg_decoder.h"
#elif CONFIG_AUDIO_SUPPORT_FLAC_DECODER
#include "flac_decoder.h"
#elif CONFIG_AUDIO_SUPPORT_WAV_DECODER
#include "wav_decoder.h"
#elif ((CONFIG_AUDIO_SUPPORT_AAC_DECODER) ||    \
        (CONFIG_AUDIO_SUPPORT_M4A_DECODER) ||   \
        (CONFIG_AUDIO_SUPPORT_TS_DECODER) ||    \
        (CONFIG_AUDIO_SUPPORT_MP4_DECODER))
#include "aac_decoder.h"
#endif
#include "esp_peripherals.h"
#include "periph_sdcard.h"
#include "board.h"


#endif
