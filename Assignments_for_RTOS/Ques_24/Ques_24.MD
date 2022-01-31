Ques_24: Write a RTOS application to demonstrate a priority inversion problem. If your RTOS 
         supports priority inheritance or priority ceiling, use it to solve the priority 
         inversion problem.
    
Answer: In Ques_24/priority_inversion program we can see that inspite of having highest priority, 
        task 'Task_H' is executing at last. This is priority inversion problem in RTOS. It can be 
        minimised by using priority inheritance.
        In FreeRTOS, mutexes include a priority inheritance mechanism, binary semaphores do not.
        So, in Ques_24/priority_inheritance program i used a mutex instead of binary semaphore.