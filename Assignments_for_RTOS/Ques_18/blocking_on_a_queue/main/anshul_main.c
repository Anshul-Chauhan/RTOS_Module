//Ques_18.: Also demonstrate blocking on a queue.

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t queue_handle;

BaseType_t queue_send;

void Task_1(void *pvParameters)
{
    int data_send = 2;
    while(1)
    {
        queue_send = xQueueSend(queue_handle, &data_send, pdMS_TO_TICKS(2000));
        if(queue_send == errQUEUE_FULL)
        {
            printf("Queue is full. Situation of blocking on a queue.\n");
        }  
        else
        {
            printf("Sent Data from Task_1: %d\n", data_send);
            data_send++;
            data_send++;
        }
    }
}

void Task_2(void *pvParameters)
{
    //int data_recv = 0;
    while(1)
    {
        vTaskDelay(10000 / portTICK_PERIOD_MS); 
        //xQueueReceive(queue_handle, &data_recv, portMAX_DELAY);
        //printf("Received Data in Task_2: %d\n", data_recv);
    }
}

void app_main()
{
    queue_handle = xQueueCreate(10, sizeof(int));
    xTaskCreate(Task_1, "Task_1", 2048, NULL, 7, NULL);
    xTaskCreate(Task_2, "Task_2", 2048, NULL, 5, NULL); 
    printf("Main Task\n");                   
}