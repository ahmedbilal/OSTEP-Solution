# Aerial View Of Chapter 7

* Scheduling Metrics (Performance)
  * **Turn Around Time** = Completion Time - Arrival Time
  * **Response Time** = First Run - Arrival Time

* Schedular Types
  * **Non-Preemptive** (Run task/process till its completion).
  * **Preemptive** (Run task/process for sometime and then switch to some other task/process.)

* Scheduling Policies
  * **First In First Out (FIFO) - Non Preemptive** | Worst Case: The first process is the biggest one *(need most processing)* thus increasing turn around time of other processes.

  * **Shortest Job First (SJF) - Non Preemptive** | Worst Case: When a bigger job come first and them some smaller jobs come after some time. These later coming jobs have to wait a lot thus increasing average turn around time.

  * **Shortest Time To Completion First (STCF) - Preemptive** | Worst Case: If all of the tasks are very big *(require a lot of cpu time)* then all non-running task have to starve for a long time *(until the running task get completed)* to get their CPU time share.

  * **Round Robin - Preemptive** All schedulling policies discussed above have bad average response time. Round robin solves this issue by giving all processes CPU time turn by turn for a fixed amount. So, no task get starved. **Round Robin** is fair scheduling policy. But, its disadvantage is that it perform poor on **turn-around metrics**.