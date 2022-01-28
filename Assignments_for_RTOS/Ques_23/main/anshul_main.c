// Ques_23: Write a RTOS application to manage resources using mutual exclusion.

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t semph;
int arr[4] = {111,222,333,444};
int count = 0;

void Task_1(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_1:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_2(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_2:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_3(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_3:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_4(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_4:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(6000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_5(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_5:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_6(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_6:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_7(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_7:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task_8(void *pvParameters)
{
    int i;
    while(1)
    {
        xSemaphoreTake(semph, portMAX_DELAY);
        i = count;
        count++;
        printf("\nIn Task_8:\nUsing resourse: %d\nValue of arr[%d] = %d\n\n", count, count, arr[i]);
        vTaskDelay(6000 / portTICK_PERIOD_MS);
        xSemaphoreGive(semph);
        count = i;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    semph = xSemaphoreCreateCounting(4, 4);
    xTaskCreate(Task_1, "Task_1", 2048, NULL, 5, NULL);
    xTaskCreate(Task_2, "Task_2", 2048, NULL, 5, NULL);
    xTaskCreate(Task_3, "Task_3", 2048, NULL, 5, NULL);
    xTaskCreate(Task_4, "Task_4", 2048, NULL, 5, NULL);
    xTaskCreate(Task_5, "Task_5", 2048, NULL, 5, NULL);
    xTaskCreate(Task_6, "Task_6", 2048, NULL, 5, NULL);
    xTaskCreate(Task_7, "Task_7", 2048, NULL, 5, NULL); 
    xTaskCreate(Task_8, "Task_8", 2048, NULL, 5, NULL);
    printf("Main Task\n");                   
}