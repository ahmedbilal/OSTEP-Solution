# Chapter 7

## Question 4

### For what types of workloads does SJF deliver the same turnaround times as FIFO?

For Jobs having same length, SJF delivers the same turnaround times as FIFO.

```shell
./scheduler.py -p LIFO -l 100,100,100 -c
```

```shell
./scheduler.py -p SJF -l 100,100,100 -c
```

Both have same turnaround.

## Question 5

### For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

If all job length *(say it x)* are same and Quantum length *(say it q)* then x = q. In this case, SJF delivers the same response times as RR.

```shell
./scheduler.py -p SJF -l 100,100,100 -c
```

```shell
./scheduler.py -p RR -l 100,100,100 -c -q 100
```

Both have same response time.

## Question 6

### What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

If we doubles each job length, average response time also get double too. It mean there is linear relationship between job length and response time.

```shell
./scheduler.py -p SJF -l 1,2,3 -c
```

```shell
./scheduler.py -p SJF -l 2,4,6 -c
```

```shell
./scheduler.py -p SJF -l 4,8,12 -c
```

## Question 7

### What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?