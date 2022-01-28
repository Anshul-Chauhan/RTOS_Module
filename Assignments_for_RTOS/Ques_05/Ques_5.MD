Ques_5: Swap the priority and observe the changes in the output. What is your conclusion on the
        sequence of printing the messages.

Answer: In Ques_5 program, i swap the priorities of task 'Task1' and 'Task2'. In both the 
        programs(Ques_4 and Ques_5) Whichever task having higher priority is executing first.
        This is happening because FreeRTOS uses 'Priority based preemptive' scheduling algorithm 
        according to which higher priority tasks will always get a chance to execute first.    