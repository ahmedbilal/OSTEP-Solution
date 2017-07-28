# Aerial View Of Chapter 9

## Proportional-Share or Fair Share Schedular

* Schedulars whose focus is to let every task get its deserved share.
* How, we determine the deserveness of some task?
  * It is completely on the operator of computer system.

## Lottery Schedular (Fair Share Schedular)

* The main idea is simple. We have to hold lottery to determine winner (job which have to run on cpu). The job which deserves more cpu time should be given more chances (more tickets) to win the lottery.

* Each job have its share (tickets). Every often lottery is held to announce the winner.

* For Example, Job A has 75 tickets and Job B has 25 tickets. Schedular have to know that there are total 100 tickets. Then schedular randomly pick one number (ticket) in 0-100 range. The job which have that number (ticket) will then run on the cpu.
  * This schedular is very fair. In previous example, we know that there is 75% chance that the winner of next lottery (cpu-time slice) would be Job A and there is 25% chance that the winner would be Job B.

## Ticket Mechanism

### Ticket Currency

* It allow user to assign tickets to its jobs in any currency it likes. The system would convert it to correct global currency.

#### For Example

We have total 100 tickets (global currency)

* User A gives 500 (A’s currency) to A1 **which corresponds to** 50 (global currency)

* User A gives 500 (A’s currency) to A2 **which corresponds to** 50 (global currency)

* User B **gives** 10 (B’s currency) to B1 **which corresponds to** 100 (global currency)

### Ticket Sharing

* Jobs/Process can share their tickets with others. **For Example**, if one job need more cpu-time slice. Other would voluntarily give that demanding job/process some of their tickets. So, that the demanding job can get more cpu time.

### Ticket Inflation

* In environments, where job/processes trust each other. One job/process which need more cpu-time can increase its tickets to get more cpu-time.


## Unfairness Metrics

Lottery schedular is based upon probablity. So, there is chance of some unfairness being introduced into the system.

Suppose there are two jobs A and B with same number of tickets and are of same length. However, sometimes A get completed first and sometimes B get completed first. It is all due to random nature of Lottery schedular.

We can measure this unfairness using simple formula

**Unfairness** = Completion Time of first ending job / Completion Time of second ending job