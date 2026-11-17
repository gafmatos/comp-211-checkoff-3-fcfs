## First-Come, First-Served Scheduling (FCFS)
 
First-come, first-served (FCFS) is the simplest CPU scheduling algorithm, it processes run in the order they arrive. New processes join the back of the ready queue, and the CPU always takes the process at the front. Once a process starts, it keeps the CPU until it finishes or blocks.
 
### C Example
 
`fcfs.c` stores each process in a `Process` struct (a simplified Process Control Block) holding its name/id, burst time, and waiting time. The `iterateProcess` function runs the processes in queue order, recording when each one starts and calculating the average waiting time. The main method runs the same three processes in two different orders.
 
Use standard gcc compilation to compile the code:
 
```
gcc fcfs.c -o fcfs
./fcfs
```
 
Running the code yields:
 
```
P1 waits  0 ms
P2 waits 24 ms
P3 waits 27 ms
Average wait: 17.00 ms
 
P2 waits  0 ms
P3 waits  3 ms
P1 waits  6 ms
Average wait: 3.00 ms
```
 
### Interpretation
 
Both runs use the same processes (P1 needs 24 ms, P2 and P3 need 3 ms each), only the arrival order changes. When the long process arrives first, the short processes are stuck waiting behind it, and the average wait is about 6× longer. This is called the **convoy effect**, and it is the main weakness of FCFS.
 
FCFS is simple to implement and fair in the sense that every process eventually runs. However, because performance depends entirely on arrival order, it is a poor fit for interactive systems, where one long job can make everything else feel unresponsive.
 
This program is a small simulation, assuming all processes arrive at time 0 and only calculates waiting times instead of actually scheduling work on a CPU.
 
As for application, FCFS shows up wherever jobs are handled in arrival order, such as print queues and batch processing systems. It is also the building block for better schedulers: Round Robin is essentially FCFS with a time limit, which prevents long processes from blocking everyone else. 
 