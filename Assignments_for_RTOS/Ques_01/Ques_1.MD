Ques_1: Find what is the task priority numbering for the RTOS you are using. eg. Higher the
        number higher the priority or vice-versa. Find the range of priority that can be assigned to a task for your RTOS.

Answer: In my FreeRTOS each task is assigned a priority from '0' to '24'(configMAX_PRIORITIES-1),
        where configMAX_PRIORITIES is defined within FreeRTOSConfig.h. If we try to give a 
        priority higher than 24 or lower than 0, then it will automatically assign '24' priority 
        to that respective task. 
        Also, in FReeRTOS low priority numbers denote low priority tasks.
        Above statements are verified in Ques_1 program.
