#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t motor_timer1_handle, motor_timer2_handle, motor_timer3_handle;

void MotorTask(TimerHandle_t xTimer)
{
    uint32_t TimerId;
    TimerId = ( uint32_t ) pvTimerGetTimerID( xTimer );
    if(TimerId == 1)
    {
        printf("Turning Motor ON\n");
    }
    else if(TimerId == 2)
    {
        printf("Increasing Motor's Speed\n");
    } 
    else
    {
        printf("Turning Motor OFF\n");
    }
}

void app_main()
{
    motor_timer1_handle = xTimerCreate("MotorOn", pdMS_TO_TICKS(4000), pdTRUE, (void *) 1, MotorTask);
    motor_timer2_handle = xTimerCreate("MotorSpeeding", pdMS_TO_TICKS(4000), pdTRUE, (void *) 2, MotorTask);
    motor_timer3_handle = xTimerCreate("MotorOff", pdMS_TO_TICKS(4000), pdTRUE, (void *) 3, MotorTask);
    xTimerStart(motor_timer1_handle, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    xTimerStart(motor_timer2_handle, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    xTimerStart(motor_timer3_handle, 0);
    
    while(1)
    {
        printf("Main Task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }                   
}