
# **THIS IS AN XV6 ASSIGNMENT.**

# XV6 Scheduler, part 1

This is the first part of changing the XV6 scheduler.

We are going to change the XV6 scheduler, which is currently a simple round robin scheduler.

Before we change the scheduler we need to set up a good testing environment: We want to create a situation where there are several processes running at a time so that we can see the change in the scheduler that we will make in part 2.

# Part 1: Fork and Exec

Create a user program in XV6 called " forkExecTest.c" which will be used to generate output that will allow us to test our scheduler and see the results on the screen. You may want to create a second C file to perform the actual counting while using forkExecTest.c to create child processes. Unlike our Linux program, you will not be setting up pipes for communication between the parent and child processes.

1.  forkExecTest takes one positive integer argument from the command line. If a positive integer argument is not passed in then give the user an error message and exit. The first argument is how many numbers each child should print on the screen. The general format is "forkExecTest X." For example, "forkExecTest 1000."
2.  If a single positive integer argument (X) is passed then do the following:
3.  Spawn (i.e. use fork and exec) to create two processes, a "high priority" and a "low priority" one, that each print out X values. Given the example above, "forkExectTest 1000" - you would spawn 1 high priority process and spawn 1 low priority processes each of which print out 1000 numbers.
4.  **Since the scheduler currently is a round robin scheduler there is no way to currently set a priority** - we will do that in part 2. So, all the spawned processes should be intermixed together.
5.  Use some sleep functions to slow down the printing of the numbers so that you can see the scheduler actually working. You will have to play with how long each process sleeps until you are happy with the speed of the printing of the numbers of each process.

# **Example**

The following is a conceptual example - in other words, you will not get processes to give the exact same behavior as this. It will depend mainly on the length of your sleep calls.

Conceptual example:

forkExecTest 100

lowPriority: 1  
lowPriority: 2  
highPriority: 1  
highPriority: 2  
lowPriority : 3  
lowPriority: 4  
highPriority: 3  
highPriority: 4

...

**Your results will vary.**

Since the current scheduler is a round robin scheduler each process (theoretically) is given the same amount of time on the CPU.

# Suggestions

I would start over with a new copy of XV6.

Don't delete your old implementation(s) of XV6 - you can use those as references to make your life easier. All you need to do is rename the directory for XV6 using the **mv** command.

**When you have finished with making your user processes and have thoroughly tested them you will be ready for part 2.**

**Save your forkTestExec.c file and the secondary C file used by the forked processes, if you made a second file (I did in mine, it just make the program a little easier).**

# XV6 Scheduler, part 2

The existing scheduler in xv6 is a Round-Robin (RR) scheduler. On each timer interrupt, the interrupt handler switches to the kernel scheduler, which then selects the next available process to run. This scheduler, while simple, is too primitive to do anything interesting.

# Part 2: Priority Scheduler

In this part of the assignment, you'll implement an advanced scheduler that schedules processes based on their priorities. Each process has a priority, and the scheduler always picks the process with the highest priority. The scheduler does RR scheduling for processes with equal priorities. Note: to simplify the assignment, assume all processes are single-threaded.

To implement this scheduler you will need to implement the following system calls:

-   `int nice(int incr);`
    
-   `int getpriority();`
    
-   `int setpriority(int new_priority);`
    

Your scheduler will support **five** possible priority classes, identified by integers 0, 1, 2, 3, 4. **The smaller the integer, the higher the priority**. For example, 0 represents the highest priority. nice(incr) system call increases or decreases the priority of the _current_ process by incr. The argument incr may be either positive or negative. For example, if the priority of the current process is 1, and after calling nice(1, the priority will become 2. The system call, nice(incr), should return 0 only when it successfully increases or decreases the priority of the current process, and should return -1 if the priority exceeds the priority range [0, 4] or upon any other failures.

The system call getpriority() retrieves the priority of the _current_ process, and setpriority(new_priority) sets new priority for the _current_ process. These system calls should return 0 only if they successfully set the priority, and should return -1 otherwise.

Your implementation must satisfy the following requirements.

Your scheduler uses multiple queues of processes. Each queue is associated with a priority class, and it contains all processes with this priority. Only the processes in the RUNNABLE state should be in one of the ready qeueus. On each timer interrupt or when the current process yields the CPU (e.g., via a call to yield()), the scheduler puts the current process to the back of the corresponding queue. It then schedules the process from the front of the ready queue with the highest priority. If the ready queue with the highest priority is empty, the scheduler goes to the next queue, and so on.

Your queues should only store processes in the RUNNABLE state. For example, if a process calls sleep(), it should not be placed in the ready queue, until it is awakened. The scheduler should put processes just created or woken up to the back of the corresponding ready queue.

The init process has priority 0 when it is spawned. When a process calls fork(), the child process should inherit the priority of the parent process

Note that to simplify this assignment, we do not ask you to implement per-CPU ready queues. **You may use any or no data structure to make it work. There are many ways (some more or less efficient than others) that I have seen that succeed.**

If you need a place to start looking to change the scheduler, look in the **proc.c** file.

# Combining with part 1

The purpose of the first part of this assignment was to create a parallel processing environment that would adequately test the scheduler. You should be able to run forkExecTest without error after implementing part 2.

For part 2 we need to change what we did in part 1 so that it uses priorities. First, make a copy of the forkExecTest.c file and rename it priTest.c. Depending on the method you used for implementing the child process that performs the counting, you may need to change the low priority and high priority, or secondary program(s) from part 1. **If you do change the programs, change the name(s) of the files and executables so both part 1 and part 2 can be tested.** When run, these programs should set their priority to the appropriate level as the first action..

When you run priTest the behavior of the program should now be different from part 1 - specifically, instead of the low priority and high priority processes interleaving their output the high priority process should print first then the low priority process should print. NOTE: There may be some differences as you first start your processes, but the high priority should clearly be higher priority, once started.

**Make sure to take out the sleeps in your printing program or your schedule may skip processes when they are in the SLEEPING state.**

# What to turn in

For this assignment you will need to create a **README** file that details every file that you changed from the original XV6 source code. Specifically, have the README file have an entry for each file similar to the following:

-   file name that was changed/created
-   how that file was changed

With the README file inside the XV6 directory compress the directory - either zip it or tar it - and turn the compressed file into canvas.

