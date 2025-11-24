# AQS

* Adam's quicksort, freshly converted from VB.NET → ANSI C.

## Program function

* This is a simple and robust quicksort algorithm in C intended to be run on a bash terminal. Instructions on how to do so can be viewed in the 'Valid usage' section below.

* The context behind this is that I thought it would be a suitable challenge to convert my A-Level teacher's old quicksort algorithm from VB.NET to C, considering my upcoming lectures at university focus on sorting & recursion.

* To view the associated documentation, feel free to check out my [documentation server](https://discord.gg/uVpFCahHBc).

## Valid usage

* Assuming the directory is that of the .C file, use this bash command to compile: '$ gcc "Adam's Quicksort.c" -o aqs'.

* And this one to run: './aqs (arguments)'. Arguments in this context refer to any integer in the range -999 → 999, with the solution requiring at least two to run.

* For example, if I run './aqs 4 1 2', it should return as output:

\# Sorted arguments: #
1
2
4
