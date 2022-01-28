/*Ques_1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
    number higher the priority or vice-versa. Find the range of priority that can be assigned to
    a task for your RTOS.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/FreeRTOSConfig.h>

TaskHandle_t xHandleTask1, xHandleTask2;

void Task1(void *pvParameters)
{
    while(1)
    {
        printf("Task1:\n");
        printf("Priority of Task1: %d\n", uxTaskPriorityGet(NULL));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void *pvParameters)
{
    while(1)
    {
        printf("Task2:\n");
        printf("Priority of Task2: %d\n", uxTaskPriorityGet(NULL));
        // vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result1, result2;
    printf("Maximum priority assigned to any task is %d.\n", configMAX_PRIORITIES);

    result1 = xTaskCreate(Task1, "Task1", 2048, NULL, 0, &xHandleTask1);
    if(result1 == pdPASS)
        printf("Task1 Created\n");
        
    result2 = xTaskCreate(Task2, "Task2", 2048, NULL, 26, &xHandleTask2);
    if(result2 == pdPASS)
        printf("Task2 Created\n");                    
}