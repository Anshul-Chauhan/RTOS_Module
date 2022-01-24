#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <freertos/queue.h>

QueueHandle_t queue_handle;

TaskHandle_t add_handle, sub_handle, mul_handle, div_handle, result_handle;

EventGroupHandle_t sensor_eg_handle;
int arr[4];
const uint32_t add_event_bit = (1 << 0);
const uint32_t sub_event_bit = (1 << 1);
const uint32_t mul_event_bit = (1 << 2);
const uint32_t div_event_bit = (1 << 3);
const uint32_t all_bits = (add_event_bit | sub_event_bit | mul_event_bit | div_event_bit);

void AddTask(void *pvParameters)
{
    int add;
    while(1)
    {
        printf("Addition Task.Sending (32+18) to ResultTask\n");
        add = 32 + 18;
        xQueueSend(queue_handle, &add, portMAX_DELAY);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, add_event_bit);
    }
}

void SubTask(void *pvParameters)
{
    int sub;
    while(1)
    {
        printf("Subtraction Task.Sending (32-18) to ResultTask\n");
        sub = 32 - 18;
        xQueueSend(queue_handle, &sub, portMAX_DELAY);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, sub_event_bit);
    }
}

void MulTask(void *pvParameters)
{
    int mul;
    while(1)
    {
        printf("Multiplication Task.Sending (32x18) to ResultTask\n");
        mul = 32 * 18;
        xQueueSend(queue_handle, &mul, portMAX_DELAY);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, mul_event_bit);
    }
}

void DivTask(void *pvParameters)
{
    int div;
    while(1)
    {
        printf("Division Task.Sending (32/18) to ResultTask\n");
        div = 32 / 18;
        xQueueSend(queue_handle, &div, portMAX_DELAY);
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        xEventGroupSetBits(sensor_eg_handle, div_event_bit);
    }
}

void ResultTask(void *pvParameters)
{
    uint32_t retVal;
    int result, i = 0;
    while(1)
    {
        retVal = xEventGroupWaitBits(sensor_eg_handle, all_bits, pdTRUE, pdTRUE, pdMS_TO_TICKS(60000));
        printf("\nResult Task.\n");
        while(i != 4)
        {
            xQueueReceive(queue_handle, &result, portMAX_DELAY);
            arr[i] = result;
            i++;
        }
        printf("Addition of 18 and 32 = %d\nSubtraction of 32 and 18 = %d\n"
        "Multiplication of 32 and 18 = %d\nDivision of 32 and 18 = %d\n", arr[0], arr[1], arr[2], arr[3]);
        i = 0;
        printf("Return Value = %d\n", retVal);
    }
}

void app_main()
{
    queue_handle = xQueueCreate(7, sizeof(int));
    sensor_eg_handle = xEventGroupCreate();
    xTaskCreate(AddTask, "Addition_Task", 2048, NULL, 5, &add_handle);
    xTaskCreate(SubTask, "Subtraction_Task", 2048, NULL, 5, &sub_handle);
    xTaskCreate(MulTask, "Multiplication_Task", 2048, NULL, 5, &mul_handle);
    xTaskCreate(DivTask, "Division_Task", 2048, NULL, 5, &div_handle);
    xTaskCreate(ResultTask, "Result_Task", 2048, NULL, 5, &result_handle);                        
}