#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>

TaskHandle_t temp_handle, pres_handle, cali_handle;

EventGroupHandle_t sensor_eg_handle;

const uint32_t temp_event_bit = (1 << 0);
const uint32_t pres_event_bit = (1 << 1);
const uint32_t all_bits = (temp_event_bit | pres_event_bit);

void TemperatureTask(void *pvParameters)
{
    while(1)
    {
        printf("Temperature Task.\n");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, temp_event_bit);
    }
}

void PressureTask(void *pvParameters)
{
    while(1)
    {
        printf("Pressure Task.\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, pres_event_bit);
    }
}

void CalibrationTask(void *pvParameters)
{
    uint32_t result;
    while(1)
    {
        printf("Calibration Task.\n");
        result = xEventGroupWaitBits(sensor_eg_handle, all_bits, pdTRUE, pdTRUE, pdMS_TO_TICKS(5000));
        printf("result = %d\n", result);
    }
}

void app_main()
{
    sensor_eg_handle = xEventGroupCreate();
    xTaskCreate(TemperatureTask, "Temperature_Task", 2048, NULL, 5, &temp_handle);
    xTaskCreate(PressureTask, "Pressure_Task", 2048, NULL, 5, &pres_handle);
    xTaskCreate(CalibrationTask, "Calibration_Task", 2048, NULL, 5, &cali_handle);                        
}