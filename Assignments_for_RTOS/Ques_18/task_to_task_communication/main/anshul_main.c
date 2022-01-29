/*Ques_18: Write a RTOS application to demonstrate the use of task to task communication using
    Queue management APIs.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t queue_handle;

void Task_1(void *pvParameters)
{
    int data = 2;
    while(1)
    {
        printf("Sent Data from Task_1: Even numbers: %d\n", data);
        xQueueSend(queue_handle, &data, portMAX_DELAY);
        data = data + 2;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_2(void *pvParameters)
{
    int data_recv = 0;
    while(1)
    {
        xQueueReceive(queue_handle, &data_recv, portMAX_DELAY);
        printf("Received Data in Task_2: Even Numbers: %d\n", data_recv);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    queue_handle = xQueueCreate(10, sizeof(int));
    xTaskCreate(Task_1, "Task_1", 2048, NULL, 7, NULL);
    xTaskCreate(Task_2, "Task_2", 2048, NULL, 5, NULL); 
    printf("Main Task\n");                   
}