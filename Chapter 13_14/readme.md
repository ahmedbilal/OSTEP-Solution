Q1
Segmentation Fault occur. Mean we are trying to access memory location that is not declared.

Q2
Program received signal SIGSEGV, Segmentation fault.
0x00000000004004e6 in main () at null.c:6
6		int value = *ptr_to_null;

Q3
When we execute our program using valgrind. It says
Invalid read of size 4
==29016==    at 0x4004E6: main (null.c:6)
==29016==  Address 0x0 is not stack'd, malloc'd or (recently) free'd

It says that we haven't declare/assign this address in either stack or heap.

Q4
Nothing bad happens/indicated when we run this program.

gdb doesn't indicated any issue.

valgrind pointed out that we allocates 4 bytes but we don't freed them on exit. So, we lost 4 bytes.

Q5
Nothing happens/indicated when we run the program.

Valgrind says Invalid write of size 4.(Mean we write something on wrong place)

and 400 bytes are lost (because we don't freed the memory we assigned)

I don't think this program is correct. Because, I think we are overwriting someone else' memory.

Q6
When we run the program. It prints 100 0's.
Valgrind says there are 100 errors. These errors are of invalid read (most probably)

Q7
When we run the program, it says "free() invalid pointer" and crashed. We don't need any tool to find out the problem.
