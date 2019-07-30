
# **THIS IS A LINUX ASSIGNMENT, not an Xv6 assignment.**

# CS-3100 Programming Assignment 6

This is an introduction to Pthreads.

### Gist

Threads are used by GUI's more than any other type of application.

We will launch new threads based on the user input. However, it will be through the command prompt.

### Your program

Your C program will get input from the user (e.g. using scanf, fgets, etc.).

Your program will convert valid input from the user (only positives integers greater than zero) and return the answer. If the user input anything other than a positive integer then immediately print out an error message.

There will only be three options, which are the following:

1) Print out your name.

2) Print out the i-th Fibonacci number. Please use recursion so that it is slower.

3) Exit the program. However, before doing so, terminate all existing pthreads that are currently running before exiting.

In the first two cases you will spawn a new thread to either print your name or print out the i-th Fibonacci number (see [https://en.wikipedia.org/wiki/Fibonacci_number](https://en.wikipedia.org/wiki/Fibonacci_number))). Our program will start with a zero (0) in the sequence.

Please ensure that when the answer is printed out that it clearly indicates what it is presenting. For example, do not simply print out the answer, because in a parallel environment this is confusing.

Do not wait for the answer to be generated before waiting for new input.

Continue to get input from the user until the user enters "3" then exit the program.

## Example
```
For example, user input:  
Welcome!  
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
1
```
My name is Robert Ball  
  
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
2
```
Please enter i:
```
2
```
Fibonacci number 2 is 1  
  
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
2
```
Please enter i:
```
8
```
Fibonacci number 8 is 13  
  
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
2
```
Please enter i:
```
23
```
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit  
  
Fibonacci number 23 is 17711
```
2
```
Please enter i:
```
36
```
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
2
```
Please enter i:
```
10
```
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit  
  
Fibonacci number 10 is 34.  
  
Fibonacci number 36 is 9227465.
```
2
```
Please enter i:
```
37
```
1) Print out my name  
2) Find the i-th Fibonacci number  
3) Exit
```
3
```
Thank you! Goodbye!
```
Note 1: The 37th Fibonnaci number would never be printed because the system exited first.  
Note 2: The exact order of what is printed out when is based on what your program does with the threads. It is expected to intermingle - that is the point!  
Note 3: **Do not try to get the exact intermingling from above** - every time the program is run it will produce a slightly different output.

