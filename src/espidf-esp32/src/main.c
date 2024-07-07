#include <stdio.h>
#include "sdkconfig.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_log.h"
#include <driver/gpio.h>
#include <rom/gpio.h>
#include <include/soc/rtc.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#ifdef DEBUG
#warning "Debug mode enabled"
#else
#warning "Release mode enabled"
#endif

static const char* TAG = "app_main";

gpio_num_t esp32Led = 1; // LED_BUILTIN

void app_main()
{
#ifdef DEBUG
    // printf("Hello world!\n");
    ESP_LOGI(TAG, "Hello world!");
#endif

#ifdef DEBUG
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    rtc_cpu_freq_config_t conf;
    rtc_clk_cpu_freq_get_config(&conf);
    uint32_t flash_size;

    ESP_LOGI(TAG, "Chip : %s", CONFIG_IDF_TARGET);
    ESP_LOGI(TAG, "CPU freq : %lu MHz ", conf.freq_mhz);
    ESP_LOGI(TAG, "CPU cores : %d", chip_info.cores);
    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    ESP_LOGI(TAG, "Revision : v%d.%d", major_rev, minor_rev);

    if(esp_flash_get_size(NULL, &flash_size) == ESP_OK)
    {
        ESP_LOGI(TAG, "Flash size : %lu MB\n", flash_size / (1024 * 1024));
    }
    ESP_LOGI(TAG, "Free RAM : %ld bytes\n", esp_get_minimum_free_heap_size());
#endif

    // Start blink
    gpio_pad_select_gpio(esp32Led);
    gpio_set_direction(esp32Led, GPIO_MODE_OUTPUT);
    while(1)
    {
        /* Blink off (output low) */
        gpio_set_level(esp32Led, 0);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
        gpio_set_level(esp32Led, 1);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}