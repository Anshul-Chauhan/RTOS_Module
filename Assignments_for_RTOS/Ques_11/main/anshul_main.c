// Ques_11: What is the API for deleting a task? Write a program demonstrate this capability.

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTask;

void Task1(void *pvParameters)    // Run to completion task
{
    printf("This is a run to completion task.\n");
    vTaskDelete(xHandleTask);    // API to delete a task
}

void app_main()
{
    BaseType_t result;
    result = xTaskCreate(Task1, "Task1", 1024, NULL, 5, &xHandleTask);
    if(result == pdPASS)
    {
        printf("Task Created\n");
    }                        
}