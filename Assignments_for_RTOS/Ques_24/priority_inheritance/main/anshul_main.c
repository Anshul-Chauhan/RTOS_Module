/*Ques_24: If your RTOS supports priority inheritance or priority ceiling, use it to solve the 
    priority inversion problem.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t semph;
int num;    // shared resource

void Task_L(void *pvParameters)
{
    xSemaphoreTake(semph, portMAX_DELAY);
    printf("Lowest priority task having semaphore lock.\n");
    for(int i = 0;  i < 7; i++)
    {
        num = i;
        if(i == 4)
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("num = %d\n", num);
        printf("This is Task_L having priority 5, using shared resousce 'num'.\n");
    }
    printf("Lowest priority task giving semaphore lock.\n");
    xSemaphoreGive(semph);
    vTaskDelete(NULL); 
}

void Task_M(void *pvParameters)
{
    printf("Medium priority task executing.\n");
    for(int i = 0;  i < 7; i++)
        printf("This is Task_M having priority 7, printing %d.\n", i+1);
    vTaskDelete(NULL); 
}

void Task_H(void *pvParameters)
{
    printf("Highest priority task waiting for semaphore.\n");
    xSemaphoreTake(semph, portMAX_DELAY);
    for(int i = 0;  i < 7; i++)
    {
        num = i;
        printf("num = %d\n", num);
        printf("This is Task_H having priority 10, using shared resousce 'num'.\n");
    }
    xSemaphoreGive(semph);
    vTaskDelete(NULL); 
}

void initTask(void *pvParameters)
{
    semph = xSemaphoreCreateMutex();  // using mutex instead of binary semaphore
    xTaskCreate(Task_L, "Task_L", 2048, NULL, 5, NULL);
    //xSemaphoreGive(semph);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    xTaskCreate(Task_H, "Task_H", 2048, NULL, 10, NULL);
    //vTaskDelay(1000 / portTICK_PERIOD_MS);
    xTaskCreate(Task_M, "Task_M", 2048, NULL, 7, NULL); 
    printf("Initial Task finishing.\n"); 
    vTaskDelete(NULL);                
}

void app_main()
{
    xTaskCreate(initTask, "Initial_Task", 2048, NULL, 12, NULL); 
}