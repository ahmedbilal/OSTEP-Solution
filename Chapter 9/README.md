# Chapter 9

## Question 1

### Compute the solutions for simulations with 3 jobs and random seeds of 1, 2, and 3.

Run all the following commands and see their output. They are different from each other because of randomness.

```bash
./lottery.py -j 3 -s 1 -c
```

```bash
./lottery.py -j 3 -s 2 -c
```

```bash
./lottery.py -j 3 -s 3 -c
```

## Question 2

### Now run with two specific jobs: each of length 10, but one (job 0) with just 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100). What happens when the number of tickets is so imbalanced? Will job 0 ever run before job 1 completes? How often? In general, what does such a ticket imbalance do to the behavior of lottery scheduling?

For job 1 to complete before job 0 begins, we must choose job 1's 100 tickets out of the total 101 ticket for ten iterations in a row. This is equal to (100/101)^ 10 ~= 0.91. Therefore, job 0 will have a 1 - 0.91 = 0.09 chance of running before job 1 finishes.

This imbalance essentially makes the system a sequential scheduler. 

## Question 3

### When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100,100:100), how unfair is the scheduler? Run with some different random seeds to determine the (probabilistic) answer; let unfairness be determined by how much earlier one job finishes than the other

```bash
./lottery.py -j 2 -l 100:100,100:100 -c -s 1
```

Unfairness Metric = 196/200 = 0.98

```bash
./lottery.py -j 2 -l 100:100,100:100 -c -s 2
```

Unfairness Metric = 190/200 = 0.95

```bash
./lottery.py -j 2 -l 100:100,100:100 -c -s 3
```

Unfairness Metric = 196/200 = 0.98

## Question 4

### How does your answer to the previous question change as the quantum size (-q) gets larger?

q-size  | unfairness
--------|------------
1       |   0.98
2       |   0.97
3       |   0.985
4       |   0.94
5       |   0.95
6       |   0.941
7       |   0.866
8       |   0.8846
9       |   0.8333
10      |   0.8

As you can see, with the increase of quantum size the unfairness grows.
