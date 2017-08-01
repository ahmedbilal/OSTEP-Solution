# Chapter 16

## Question 1

### First let’s use a tiny address space to translate some addresses. Here’s a simple set of parameters with a few different random seeds; can you translate the addresses?

```bash
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0
```

#### VA  0: 0x0000006c (decimal:  108) --> PA or segmentation violation?

1. **Convert the VA into decimal** (108) base 10 = (1101100) base 2

1. **Determine the Segment**
   * (log2(address size) - 1)th bit is the segment bit.
   * In our case 1101100 it is 1 (The bit on the most significat position is segment bit).
   * It is telling that this virtual address is referring to some physical address
     in segment 1.
1. As our desired mem. location is in segment 1 whose growth is negative.
   So, we have to use slightly different formula to get correct offset.

   **Offset = Decimal Representation of (All Bits except Segment Bit (101100)) - Max. Segment**

   * We can calculate max segment value by **2^[log2(address size) - number of segment bits]**

   * Max Segment = 2^(log2(128) - 1) = 2^(7 - 1) = 2^(6) = 64

   So, our Offset calculation is as follow
   * Offset = Decimal Representation of 0b101100 - 64
     * Offset = 44 - 64 = -20

   * Absolute of Offset should be less or equal than Bounds(Limit)
     * |-20| <= 20 True (Valid)

1. **Physical Address = Base + Offset** = 512 - 20 = 492

Answer = VA  0: 0x0000006c (decimal:  108) --> Valid in Segment 1; 0x1ec or in decimal 492

> **VA  1: 0x00000061 (decimal:   97) --> PA or segmentation ?violation?**

VA = 0b1100001

Seg 1

Offset = 33-64 = -31

|-31| > 20

So, Answer = Segmentation Fault

> **VA  2: 0x00000035 (decimal:   53) --> PA or segmentation violation?**

VA = 0b0110101

Seg 0

**Note that the formula for segment 0 is different because its growth is positive.**

Offset = Decimal Representation of (All Bits except Segment Bit

Offset = 53

|53| > 20

So, Answer = Segmentation Fault

> **VA  3: 0x00000021 (decimal:   33) --> PA or segmentation violation?**

VA = 0b0100001

Seg 0

Offset = 33

33 > 20

So, Answer = Segmentation Fault

> **VA  4: 0x00000041 (decimal:   65) --> PA or segmentation violation?**

VA = 0b1000001

Seg 1

Offset = 1 - 64 = -63

|-63| > 20

So, Answer = Segmentation Fault

:closed_book::closed_book::closed_book::closed_book:

### Do the Following part yourself

```bash
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1
```

```bash
segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2
```