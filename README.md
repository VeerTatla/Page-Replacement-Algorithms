File Manifest:
1.) PageReplacement.c   --> Main Program to run page replacement
2.) PageReplacement.h   --> Header file for PageReplacement.c
3.) Clock.c             --> Clock page replacement algorithm
4.) Clock.h             --> Header for Clock.c
5.) Optimal.c           --> Optimal page replacement algorithm
6.) Optimal.h           --> Header file for Optimal.c
7.) SecondChance.c      --> Second Chance page replacement algorithm
8.) SecondChance.h      --> Header file for SecondChance.c
9.) Makefile            --> Simple make file for program
10.) pages.txt          --> Sample reference strings

Compile and run instructions:
At the command line to compile type-
$ make
Then to run executable simply type-
$ a2

Significant design choices:
We decided to have the main function small. We had main call another
function that had all the page replacement function inside of it.
Each page replacement function led to its own C file. 
 

Lessons learned:
We learned a lot about the various page replacement algorithms and 
how they work and are implemented. Through analysis of different inputs 
realized that Clock and Second Chance essentially perform in the same 
manner but with different data structures. Clock page replacement
runs slightly faster than the Second Chance page replacement algorithm.
The optimal page replacement algorithm ran with the fewest page faults 
making this the ideal candidate. 

Analysis Results:

String 1- 3 9 1 3 4 8 7 6 8 4

Frame Length: 3
Clock - 8
Optimal - 7
Second Chance - 8

Frame Length: 2
Clock - 10
Optimal - 8
Second Chance - 10

Frame Length: 5
Clock - 7
Optimal - 7
Second Chance - 7
--------------------------------------

String 2 - 1 2 3 5 4 9 11 8 1 3 11 5 4 7 6 11

Frame Length: 3
Clock - 16
Optimal - 13
Second Chance - 16

Frame Length: 4
Clock - 15
Optimal - 12
Second Chance - 15

Frame Length: 6
Clock - 15
Optimal - 10
Second Chance - 15

Summary:
Optimal will give you the least amount of page faults.
The clock and second chance page replacement algorithms will
give you same amount of page faults.
