# Chapter 17

## Question 1

### First run with the flags -n 10 -H 0 -p BEST -s 0 to generate a few random allocations and frees. Can you predict what alloc()/free() will return? Can you guess the state of the free list after each request? What do you notice about the free list over time?

Yes, it is predictable if we are told the following things in advances

1. Base Address = 1000
1. Heap Size = 100

Free list become conjested over time with smaller and smaller size of free space block.

### Output

ptr[0] = Alloc(3)  returned 1000 (searched 1 elements)
Free List [ Size 1 ]:  [ addr:1003 sz:97 ] 

Free(ptr[0]) returned 0
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:97 ] 

ptr[1] = Alloc(5)  returned 1003 (searched 2 elements)
Free List [ Size 2 ]:  [ addr:1000 sz:3 ] [ addr:1008 sz:92 ] 

Free(ptr[1]) returned 0
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ] 

ptr[2] = Alloc(8)  returned 1008 (searched 3 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ] 

Free(ptr[2]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ] 

ptr[3] = Alloc(8)  returned 1008 (searched 4 elements)
Free List [ Size 3 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ] 

Free(ptr[3]) returned 0
Free List [ Size 4 ]:  [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ] 

ptr[4] = Alloc(2)  returned 1000 (searched 4 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ] 

ptr[5] = Alloc(7)  returned 1008 (searched 4 elements)
Free List [ Size 4 ]:  [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1015 sz:1 ] [ addr:1016 sz:84 ]

## Question 2

### How are the results different when using a WORST fit policy to search the free list (-p WORST)? What changes?

Worst fit policy split and use the largest free memory block. Thus the returned small block were not used until the larger free mem. blocks are not splitted and used.

## Output

ptr[0] = Alloc(3)  returned 1000
List? [addr:1003, size:97]

Free(ptr[0]) returned 0
List? [(addr:1000, size:3), (addr:1003, size:97)]

ptr[1] = Alloc(5)  returned 1003
List? [(addr:1000, size:3), (addr:1008, size:92)]

Free(ptr[1]) returned 0
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:92)]

ptr[2] = Alloc(8)  returned 1008
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1016, size:84)]

Free(ptr[2]) returned 0
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:8), (addr:1016, size:84)]

ptr[3] = Alloc(8)  returned 1016
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:8), (addr:1024, size:76)]

Free(ptr[3]) returned 0
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:8), (addr:1016, size:8)(addr:1024, size:76)]

ptr[4] = Alloc(2)  returned 1024
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:8), (addr:1016, size:8)(addr:1026, size:74)]

ptr[5] = Alloc(7)  returned 1026
List? [(addr:1000, size:3), (addr:1003, size:5), (addr:1008, size:8), (addr:1016, size:8)(addr:1033, size:67)]

## Question 3

### What about when using FIRST fit (-p FIRST)? What speeds up when you use first fit?

The lookup for enough empty space slot speeds up when we use first fit. Because, we don't have to examine all the available slots. We just allocate the first fitting memory block to the job requestion memory in heap.

## Question 4

### For the above questions, how the list is kept ordered can affect the time it takes to find a free location for some of the policies. Use the different free list orderings (-l ADDRSORT, -l SIZESORT+, -l SIZESORT-) to see how the policies and the list orderings interact.

Time remain unaffected in both best and worst fit policy because these have to scan the whole list. However, in first fit only sizesort- (descending order) decrease the time to find a free location because first fit chooses the appropriate size free location that come first. So, if the largest free memory location is head of list then all allocation are from this free mem. block because it fulfills the requirement of first fit policy.

## Question 5

### Coalescing of a free list can be quite important. Increase the number of random allocations (say to -n 1000). What happens to larger allocation requests over time? Run with and without coalescing (i.e., without and with the -C flag). What differences in outcome do you see? How big is the free list over time in each case? Does the ordering of the list matter in this case?

Larger allocation requests failed in free mem. mechanism without coalescing because in that case free list would be filled with small free mem. blocks. Without coalescing the free list became conjested with a lot of small free memory blocks. This conjestion also increase look up time in nearly all free mem. lookup policies.  The ordering of the list matters only in first fit free mem. location policy.

## Question 6

### What happens when you change the percent allocated fraction -P to higher than 50? What happens to allocations as it nears 100? What about as it nears 0?

Than Most heap operation would be allocation operation. When we increase the percent allocated fraction to near 100 or 100. Then nearly all operations would be allocation operations. If we approach 0 the allocations and free operation are done in 50%. Because, we can't free memory that isn't allocated. So, to free mem. we have to allocate some first.

## Question 7

### What kind of specific requests can you make to generate a highly fragmented free space? Use the -A flag to create fragmented free lists, and see how different policies and options change the organization of the free list.

```bash
./malloc.py -n 6 -A +1,-0,+2,-1,+3,-2 -c
```