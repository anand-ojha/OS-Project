# OS-Project

My project for subject Operating System is to make a program that considers a scheduling approach which is non pre-emptive similar to shortest job next in nature. The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite postponement. The jobs that have spent a long time waiting compete against those estimated to have short run times. The priority can be computed as :

Priority = 1+ Waiting time / Estimated run time

Initially, i understood what is shortest job first algoritm for scheduling approach. Then i learnt about preemptive and non preemptive scheduling. 

After this, I made a c program which takes input from user for number of processes and then their burst time respectively. then, it schedules all the processes based on shortest job first non preemptive scheduling.
