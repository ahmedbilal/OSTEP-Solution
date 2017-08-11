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