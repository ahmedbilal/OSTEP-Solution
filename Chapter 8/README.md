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

Job 0 will do 99 seconds of work, 1 second of fake IO, and then return to to 99 seconds of work again. 

```bash
./mlfq.py -l 0,1000,99:0,1000,0 -q 100 -i 1 -I -S```
```

## Question 5
###  Given a system with a quantum length of 10 ms in its highest queue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single longrunning (and potentially-starving) job gets at least 5% of the CPU?

Time quantum would have to be 200 seconds.
A longrunning job would initially get 10s in Q1.
Let us assume worst-case, which is that Q1 is 100% utilized so the job would be demoted and would have to wait an additional 180s before getting priority boosted.
This would let the job run 10/200=.05=5% of the time steps.


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
