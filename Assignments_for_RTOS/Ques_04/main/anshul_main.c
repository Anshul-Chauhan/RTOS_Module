// Ques_4: Create two task with priority 10 and 20. Each task prints its own custom message.

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


TaskHandle_t xHandleTask, xHandleTask1, xHandleTask2;

void Task1(void *pvParameters)
{
    while(1)
    {
        printf("Task1: Priority = 10\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void *pvParameters)
{
    while(1)
    {
        printf("Task2: Priority = 20\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void init_task(void *pvParameters)
{
    printf("Initial task: Priority = 22\n");
    xTaskCreate(Task1, "Task1", 1024, NULL, 10, &xHandleTask1);
    xTaskCreate(Task2, "Task2", 1024, NULL, 20, &xHandleTask2); 
    vTaskDelete(xHandleTask);
}

void app_main()
{
    xTaskCreate(init_task, "Initial_Task", 2048, NULL, 22, &xHandleTask);                      
}