/*Ques_2: What is the mechanism used to make a task periodic for the RTOS you are using? Write a
    program to make a task periodic with periodicity of 500ms.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask;

void PeriodicTask(void *pvParameters)
{
    while(1)
    {
        printf("A Periodic Task with periodicity of 500ms and priority of 5.\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t result;
    result = xTaskCreate(PeriodicTask, "Periodic Task", 1024, NULL, 5, &xHandleTask);
    if(result == pdPASS)
    {
        printf("Task Created\n");
    }                  
}