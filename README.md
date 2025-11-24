# AQS

* Adam's quicksort, freshly converted from VB.NET → ANSI C.

## Program function

* This is a simple and robust quicksort algorithm intended to be run in a bash environment. Instructions on how to do so can be viewed in the 'Valid usage' section below.

* The context behind this project is that I thought it would be a suitable challenge to convert my A-Level teacher's quicksort algorithm from VB.NET to C, considering my upcoming university lectures focus on sorting & recursion.

* To view the associated documentation, please check out my [Discord server](https://discord.gg/uVpFCahHBc).

## Valid usage

* Assuming the directory is that of the .c file, use this bash command to compile:  

`$ gcc "Adam's Quicksort.c" -o aqs`

* And this one to run:

`$ ./aqs (arguments)`
*Arguments refer to at least two integers in the range -999 → 999.*

* For example, if I run: 

`$ ./aqs 4 1 2`

* It should return:

```
$ # Sorted arguments: #
1
2
4
```
