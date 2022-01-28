/*Ques_25: Write a RTOS application to create a software timer that invokes a callback function 
    every 5 seconds.*/

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t timer_handle;

void Timer_1(TimerHandle_t xTimer)
{
    printf("Callback function of Timer1.\n");
}

void app_main()
{
    timer_handle = xTimerCreate("Timer1", pdMS_TO_TICKS(5000), pdTRUE, NULL, Timer_1);

    xTimerStart(timer_handle, 0);
    int i = 0;
    while(1)
    {
        printf("Time: %d s\n", i);    
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        i++;
    }  
}