# Chapter 18

## Question 1

### Before doing any translations, let’s use the simulator to study how linear page tables change size given different parameters. Compute the size of linear page tables as different parameters change. Some suggested inputs are below; by using the -v flag, you can see how many page-table entries are filled. First, to understand how linear page table size changes as the address space grows:

```bash
paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0

paging-linear-translate.py -P 1k -a 2m -p 512m -v -n 0

paging-linear-translate.py -P 1k -a 4m -p 512m -v -n 0
```

### Then, to understand how linear page table size changes as page size grows:

```bash
paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0

paging-linear-translate.py -P 2k -a 1m -p 512m -v -n 0

paging-linear-translate.py -P 4k -a 1m -p 512m -v -n 0
```

### Before running any of these, try to think about the expected trends. How should page-table size change as the address space grows? As the page size grows? Why shouldn’t we just use really big pages in general?

Page table size increases as the address space grows because we need more pages to cover the whole address space. When Page sizes increases the page table size decreases because we need less pages (because they are bigger in size) to cover the whole address space.

We should not use really big pages in general because it would be a lot of waste of memory. Because, most processes use very little memory.

## Question 2

### Now let’s do some translations. Start with some small examples, and change the number of pages that are allocated to the address space with the -u flag . For example:

```bash
paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 0

paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 25

paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 50

paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 75

paging-linear-translate.py -P 1k -a 16k -p 32k -v -u 100
```

### What happens as you increase the percentage of pages that are allocated in each address space?

1. Address space is not used (not filled). Thats why every memory access failed to succeed.
1. Only VA 0x2bc6 is valid.
    1. As address space is 16KB so we would have 14bits in total. However, our page size is 1kb so we need 10 bits to move around in our page. So, the other 4 bits would be used as index to our page table.
    1. The binary of 0x2bc6 is 10 1011 1100 0110
    1. So, the VPN is 1010 mean the value of 10th index of Page Table is PPN
    1. The Offset is 11 1100 0110
    1. By Looking into page table we get 0x13 at 10th index.
        1. However, we have to left shift it 10 times (number of offset bits)
        1. So, it becomes 0100 1100 0000 0000
    1. Then, we have to OR this with out offset (0011 1100 0110 OR 0100 1100 0000 0000)
    1. It finally becomes 0x4FC6

Do, all the others yourself or see va2pa.c implementation for more detais.

As, the percentage of pages that are allocated or usage of address space is increased more and more memory access operations become valid however free space decreases.

## Question 3

### Now let’s try some different random seeds, and some different (and sometimes quite crazy) address-space parameters, for variety:
```bash
paging-linear-translate.py -P 8 -a 32
-p 1024 -v -s 1

paging-linear-translate.py -P 8k -a 32k -p 1m
-v -s 2

paging-linear-translate.py -P 1m -a 256m -p 512m -v -s 3
```

### Which of these parameter combinations are unrealistic? Why?

1. Too Small Size

## Question 4

### Use the program to try out some other problems. Can you find the limits of where the program doesn’t work anymore? For example, what happens if the address-space size is bigger than physical memory?

It won't work when
1. page size is greater than address-space.
1. address space size is greater than the physical memory.
1. physical memory size is not multiple of page size.
1. address space is not multiple of page size.
1. page size is negative.
1. physical memory is negative.
1. address space is negative.