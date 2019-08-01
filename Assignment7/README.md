# **THIS IS A LINUX ASSIGNMENT.**

# CS-3100 Programming Assignment 7

This is my awesome last assignment on Pthreads.

**The gist**: You will create a single program that will create five (5) threads using a variant of the sloppy counter and report how long it takes using various thresholds and different number of processors. You will do this with two processor configurations.

**What you are doing**:

You will create a report on how the threshold of the sloppy counter affects the speed of the program with a different number of processors. This is a measure of the impact synchronization has on performance in concurrent programming.

The sloppy counter program will count up to 5 billion (1 billion per thread). You may use smaller numbers (e.g. 10 million, 100 million, etc.) as long as you can see a noticeable difference between thresholds.

Report how long it takes your program to complete with varying thresholds (use the time functions from previous assignments).

Your first threshold will be 1. In other words, every time a thread reaches the threshold, 1 in this case, it will lock the global counter, increment it by the local counter, unlock the global counter, then continue.

You should run your program on each threshold at least 5 times and average the time it takes. So, for example, if it takes 30 seconds to run the program with a threshold of 1 the first time, then 30.2 seconds the second time, 28.8 seconds, the third time, etc., you will report the average of the five times.

**Changing the number of processors (cores) used:**

With your virtual machine you will change the number of processors that Linux uses.

First determine how many processors your host operating system has. VirtualBox will tell you, but here is another way to confirm how many processors/cores are available:

1.  Linux: In the command prompt type: nproc.
2.  Mac: In the command prompt type: sysctl -n hw.ncpu
3.  Windows: In the command prompt type: echo %NUMBER_OF_PROCESSORS% (To get to the command prompt open up cmd.exe.)

To change the number of processors that VirtualBox uses perform the following steps:

1.  In VirtualBox make sure that your instance of Linux is shut down.
2.  With your instance of Linux highlighted (it will be if you only have one) then click on "Settings."
3.  Click on "System."
4.  Click on "Processor."
5.  Using the top slider you can change the number of CPU's that will be used for your instance of Linux.

**Thresholds**

The following are the thresholds: 1, 2, 5, 10, 20, 30, 40, 50 ,60, 70, 80, 90, and 100.

Since there are 13 thresholds and your program will run five (5) times per threshold then your program will run 65 times.

You will do the same thing with another processor configuration as well. So, 65 times with one processor configuration (e.g. 1 core) and 65 times with another processor configuration (e.g. 4 cores).

**NOTE**: Your program must start and then exit - you cannot just run a bunch of for loops inside your program. (That does not mean you can't have loops in your program, it just means that your program has to start and exit 65 times with varying command-line arguments).

**Suggestion**: I suggest that you learn how to do a basic bash script. If the program takes command-line arguments then the bash script will not be too onerous: that way you can use loops in bash to automate the running of your program. A good resource is ss64.com. For a quick hint:

```
for Threshold in 1 2 5 10 20 ; do
    for i in {1..5}; do
        ./hw7 1000000000 $Threshold
    done
done
```

Will run the program hw7 with two parameters of a count and threshold 5 times for each of the thresholds listed in the first for statement. Don't forget, each script should start with a "shebang" and the path of the interpreter for the script... such as  
#!/bin/bash  
to use bash as the scripting language.

**Report**  
  
NOTE: You can use whatever tools you want to create the report (e.g. Word, Excel, notepad, hand-written paper that is scanned in, etc.).  
  
Create a report that has the following information, corresponding roughly to pages:

-   Page 1: Title page. Put your name and any other identifying information here.
    
-   Page 2: You will make either one (1) chart with the results of both processor configurations on it or two (2) charts each with the result of a processor configuration on it. Chart the average times per run by the times it took to finish. Make the chart(s) look readable! I suggest making the chart(s) take up the entire first page of your report (after the title page). This is most of your grade! Also, show it to someone. Do they understand the chart(s)? Do good chart etiquette: chart title, x-axis label, y-axis label, etc.
    
-   Page 3: What does it mean? Explain using a single paragraph to 1000+ pages what your chart means. Be succinct but also be complete. This page explains your chart. Make sure to **conclude something**! Most people will only have to write a small paragraph. What "small" means varies from person to person... Tell me what it means in your words.
    
-   Page 4: How you ran your program 65 times. If you used a bash script, this is where it goes. If you manually ran it 65 times this is where you lamely admit that and show how you did it (i.e., type out the 65 program command arguments ... again).
    

Provide your c program source as an attachment or appendix to your report. It does not have to be included in the report document.

