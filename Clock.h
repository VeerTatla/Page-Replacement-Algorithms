/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* Clock.h
*
* Header file for Clock.c program. 
*/
unsigned clock_simulate(unsigned page[], unsigned pagesLen, unsigned tableLen);
void clock(unsigned * pg, unsigned pagesLen, int page_file_len);
int search_for(int *pgHit, int * frameNum, int pageNum, const int frameLen);
