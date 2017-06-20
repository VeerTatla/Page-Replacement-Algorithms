/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* SecondChance.c
*
* This program runs the second chance page replacement algorithm. 
*/
#include <stdio.h>
#include <stdlib.h>
#include "SecondChance.h"
#include "PageReplacement.h"

#define REF 1
#define NOT_REF 0

//Parameters are sent to main second chance function.

unsigned second_chance_simulate(unsigned page[], unsigned pagesLen, unsigned tableLen) {

	
    	printf("\n");
    
    	second_chance(page, pagesLen, tableLen);
    
    	return 0;



}

void second_chance(unsigned * pg, unsigned pagesLen, const int frameLen) {

	int pageFaultCnt = 0;
	int ptr = 0;
	int pageHit, j, k, a, currPage, position;
	
	int * frameCnt = malloc(sizeof(int)* frameLen);
	
	for(j = 0; j< frameLen; j++){
	
		frameCnt[j] = -1;
	
	}
	
	int *referenced = malloc(sizeof(int)* frameLen);
	for(k = 0; k < frameLen; k++){
	
		referenced[j] = 0;
	
	}
	
	a = 0;
	while( a < pagesLen) {
	
		ptr = ptr % frameLen;
		currPage = pg[a];
		
		pageHit = 0;
		
		position = search(&pageHit, frameCnt, currPage, frameLen);
		
		if(pageHit == REF) {
		
			if(frameCnt[ptr] != -1) {
			
				referenced[position] = 1;
			
			}
			
			a++;
		
		} else if(pageHit == NOT_REF) {
		
			if(referenced[ptr] == 0){
			
				frameCnt[ptr] = currPage;
				
				if(frameCnt[ptr] != -1) {
				
					referenced[ptr] = 1;
				
				}
				
				a++;
				ptr++;
				pageFaultCnt++;
			
			} else if(referenced[ptr] == 1){
			
				referenced[ptr] = 0;
				ptr++;
			
			}		
		} 
		
		
	
	}
	
	printf("\nPage Faults for Second Chance algorithm: %d\n", pageFaultCnt);
	printf("\n-----------------------------------------\n");
    

}

int search(int *pageHit, int * frameCnt, int currPage, const int frame_len) {

	int j;
	
	for(j = 0; j < frame_len; j++) {
	
		if(currPage ==frameCnt[j]) {
		
			*pageHit = 1;
			return j;
		
		}
	
	}
	
	return -1;

}
