# Aerial View Of Chapter 8

## Multi-level Feedback Queue (MLFQ)

* Optimize Both Turnaround Time and Response Time
* Have many **priority** queues.

### Rules

* If Priority(A) > Priority(B), then A runs (B doesn't)
* If Priority(A) == Priority(B), then A & B run in RR.
* When a job enters the system, it is placed on the most priority queue.
* Once a job consume its cpu time share at a given level its priority is lowered thus moved to lower priority queue.
  * *Previously we were using some different mechanism for lowering the priority of job (specifically we were not decreasing priority of jobs which voluntarily give cpu back before end of its cpu time slice). However, we saw that such policy can be gamed.*
* After some time period **S**, move all jobs to highest priority queue thus preventing starvation.