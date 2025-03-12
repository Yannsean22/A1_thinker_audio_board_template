#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nvs_flash.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <esp_log.h>
#include <esp_err.h>
#include <driver/i2c.h>
#include "driver/i2s_std.h"
#include "driver/gpio.h"
#include "esp_bt.h"
#include "board.h"
#include "es8388.h"

#define EXAMPLE_SAMPLE_RATE     (44100)
#define EXAMPLE_MCLK_MULTIPLE   (256)
#define EXAMPLE_RECV_BUF_SIZE   (2400)
#define I2S_WRITE_TIMEOUT_MS    (1000)


#endif