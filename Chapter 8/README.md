# Chapter 8

## Question 1

### Run a few randomly-generated problems with just two jobs and two queues; compute the MLFQ execution trace for each. Make your life easier by limiting the length of each job and turning off I/Os.

You can use the following commands to generate problems.

```bash
./mlfq.py -j 2 -n 2 -m 10 -M 0
```

and

```bash
./mlfq.py -j 2 -n 2 -m 20 -M 0
```

## Question 2

### How would you run the scheduler to reproduce each of the examples in the chapter?

#### Example 1

```bash
./mlfq.py -n 3 -l 0,200,0 -c
```

#### Example 2

```bash
./mlfq.py -n 3 -l 0,200,0:100,20,0 -c
```

### Example 3

```bash
./mlfq.py -n 3 -i 9 -l 0,20,1:0,200,0 -c
```

## Question 3

### How would you configure the scheduler parameters to behave just like a round-robin scheduler?

If we add --numQueues=1 then scheduler would perform like RR scheduler.

## Question 4

### Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the -S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.

From Time 0 to 201, Job 0 runs for 200 time unit while Job 1 runs for 2 time unit. So, Job 0 runs for 99% of time during this particular interval.

```bash
./mlfq.py -n 3 -i 0 -l 0,200,1:0,50,0 -S -c -Q 2,2,3
```

## Question 5
###  Given a system with a quantum length of 10 ms in its highest queue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU?

The answer is '200ms'. Time quantum of question 5 is '10ms'. After Job1 is executed in 10ms, priority will be lowered. If other jobs that has lower than 10ms, then job1 will not get any chance of execution.

So this is the situation that we have to solve. If we boost properly(like at least 5% in this problem), it will regain its priority to be in queue. Equation will be like this.

<!--we have to devide 10ms to X because Job1 is at least executed once-->

$(10ms/X)*100>=0.05$ 

$X<=200ms$

Assume that we have 200ms boost period. When Job1 was executed by 10ms and priority get lowered, boost will give every job a highest priority. Job1 will get guaranteed execution time at least 5% (That means if you set boost time lower than 200ms Job1 will get higher CPU time)

## Question 6

### One question that arises in scheduling is which end of a queue to add a job that just finished I/O; the -I flag changes this behavior for this scheduling simulator. Play around with some workloads and see if you can see the effect of this flag.

Compare

```bash
./mlfq.py -l 0,20,9:0,30,12 -s 1 -c -i 0 -S
```

with this

```bash
./mlfq.py -l 0,20,9:0,30,12 -s 1 -c -i 0 -S -I
```

When we add -I flag it place the job on the head of list after it finishes I/O.

The above commands form an example in which we use -S and -I flag to completely monoplize the cpu-time. Job 1 wasn't be able to run on CPU until Job 0 get completed.
