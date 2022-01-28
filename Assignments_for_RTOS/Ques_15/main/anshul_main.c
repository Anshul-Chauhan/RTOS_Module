// Ques_15. Create a task to suspend itself after 1200 ms and resume it from another task.

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask1;

void Task1(void *pvParameters)    
{
    printf("Task1 is going to suspend itself after 1200ms.\n");
    vTaskDelay(1200 / portTICK_PERIOD_MS);
    vTaskSuspend(NULL);
    while(1)
    {
        printf("Task1 resumed by Task2.\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void *pvParameters)    
{
    printf("Task2 is going to resume Task1.\n");
    vTaskResume(xHandleTask1);
    vTaskDelete(NULL);
}

void app_main()
{
    xTaskCreate(Task1, "Task1", 2048, NULL, 5, &xHandleTask1);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    xTaskCreate(Task2, "Task2", 2048, NULL, 5, NULL);
}