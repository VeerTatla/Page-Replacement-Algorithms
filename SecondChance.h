/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* SecondChance.h
*
* Header file for SecondChance.c program. 
*/
unsigned second_chance_simulate(unsigned page[], unsigned pagesLen, unsigned tableLen);

void second_chance(unsigned * pg, unsigned pagesLen, const int frameLen);

int search(int *pageHit, int * frameCnt, int currPage, const int frame_len);
