#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


TaskHandle_t xHandleTask, xHandleTask1, xHandleTask2;

void init_task(void *pvParameters)
{
    printf("Initial task: Priority = 6\n");
    xTaskCreate(Task1, "Task1", 1024, NULL, 5, &xHandleTask1);
    xTaskCreate(Task2, "Task2", 1024, NULL, 5, &xHandleTask2); 
    printf("Initial task is finishing after creating two tasks with same priorities.\n");
}

void Task1(void *pvParameters)
{
    while(1)
    {
        printf("Task1: Priority = 5\n");
    }
}

void Task2(void *pvParameters)
{
    while(1)
    {
        printf("Task2: Priority = 5\n");
    }
}

void app_main()
{
    xTaskCreate(init_task, "Initial_Task", 1024, NULL, 6, &xHandleTask);                      
}