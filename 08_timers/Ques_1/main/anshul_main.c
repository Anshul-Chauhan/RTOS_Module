#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t motor_timer_handle;

void TurnOffMotor(TimerHandle_t xTimer)
{
    printf("Turning motor off.\n");
}

void app_main()
{
    motor_timer_handle = xTimerCreate("MotorOff", pdMS_TO_TICKS(2000), pdFALSE, NULL, TurnOffMotor);

    xTimerStart(motor_timer_handle, 0);
    while(1)
    {
        printf("Main Task\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }                   
}