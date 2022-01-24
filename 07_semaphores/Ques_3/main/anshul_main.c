#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t mutex;

char string_buffer[50] = "This is a global shared resource.";  // Shared Resource
int sum;

void Task_1(void *pvParameters)
{
    while(1)
    {
        xSemaphoreTake(mutex, portMAX_DELAY);
        printf("\nIn Task_1: %s\n", string_buffer);
        sum = 98 + 43;
        printf("sum of 98 and 43 is %d\n", sum);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        xSemaphoreGive(mutex);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_2(void *pvParameters)
{
    while(1)
    {
        xSemaphoreTake(mutex, portMAX_DELAY);
        printf("\nIn Task_2: %s\n", string_buffer);
        sum = 8 + 23;
        printf("sum of 8 and 23 is %d\n", sum);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        xSemaphoreGive(mutex);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    mutex = xSemaphoreCreateMutex();
    xTaskCreate(Task_1, "Task_1", 2048, NULL, 5, NULL);
    xTaskCreate(Task_2, "Task_2", 2048, NULL, 7, NULL); 
    printf("Main Task\n");                   
}