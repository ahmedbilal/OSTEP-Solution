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

If you have some answer for this question please email me or commit and request push.

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