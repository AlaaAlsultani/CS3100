# **THIS IS AN XV6 ASSIGNMENT.**

# Before you begin

Download XV6 and make sure that it can run.

# Assignment

In this homework, you will add a system call to the XV6 Operating System. Before you begin this project, you'll need to be able to setup your environment to run xv6. (Hopefully you did this in the homework 2).

We'll be doing kernel hacking projects in xv6 , a port of a classic version of unix to a modern processor, Intel's x86. It is a clean and beautiful little kernel, and thus a perfect object for our study and usage.

The goal of the project is simple, to add four system calls to xv6. The following are your new system calls:

1.  void incMagic(int value)
2.  int getMagic(void)
3.  void getProcName(void)
4.  void modProcName(char* newName)

NOTE: For incMagic, getProcName, and modProcName you may return an int value if you would like in order to conform to most of the rest of the Xv6 system calls.

For the `incMagic(int value)` function you will modify the cpu struct. You will add an "int magic" variable to the struct. At the beginning of the initiation of the OS, set magic to zero. When "incMagic(int value)" is called it will increment "magic" by "value".

For the `getMagic()` function you will return the current value of "magic."

For the `void getProcName()` function you print out the name of the current process. Xv6 system calls can only return an int.

For the `void modProcName(char* newName)` function you will modify the name of the current process to `newName`.

# Details

You will have to modify a number of files in order to make this work.

Refer to your work from Homework 2 to refresh your memory on what files you discovered that effect system calls.

# Getting Started

Find some other system call, like getpid() . Basically, copy it in all the ways you think are needed. Then modify it to do what you need. To find where changes might be necessary, look for where getpid exists in the Xv6 codebase using a command like:

 `grep getpid * `

Most of the time will be spent on understanding the code. There shouldn't be a whole lot of code added although you will have to modify a number of different files.

Using gdb (the debugger) may be helpful in understanding code, doing code traces, and is helpful for later projects too. Get familiar with this fine tool!

There is not a lot of documentation - this is normal. Try to find documentation on exactly how the current Linux kernel works. You won't find it...

# Write Your Code

You may also find the following book about Xv6 useful, written by the same team that ported Xv6 to x86 book:

[http://pdos.csail.mit.edu/6.828/2014/xv6/book-rev8.pdf (Links to an external site.)Links to an external site.](http://pdos.csail.mit.edu/6.828/2014/xv6/book-rev8.pdf) (also found in the modules section). Particularly useful for this project: Chapters 0 and 3 (and maybe 4).

# Test Your Code

Use the following code to test your code. You need to add a file called HW4.c to your Makefile (just like you did in HW2).

Feel free to expand on the test file and add your own ideas.
```c
#include <????> //include all libraries that are necessary  
  
#include <????>  
  
int  
main(int argc, char *argv[]){  
    int magic = getMagic();  
    printf(1, "current magic number is the following: %d\n",magic);  
  
    incMagic(3);  
  
    magic = getMagic();  
    printf(1, "current magic number is the following: %d\n",magic);  
  
    printf(1, "current process name:");  
  
    getProcName();  
  
    printf(1,"\n");  
  
    modProcName("newName");  
  
    getProcName();  
  
    magic = getMagic();  
    printf(1, "current magic number is the following: %d\n",magic);  
  
    incMagic(3);  
  
    magic = getMagic();  
    printf(1, "current magic number is the following: %d\n",magic);  
  
    exit();  
}
```
