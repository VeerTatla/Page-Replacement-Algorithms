/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* Clock.c
*
* This program runs the Clock page replacement algorithm. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "PageReplacement.h"
#include "Clock.h"
#define REFERED 1
#define NOT_REFERED 0



unsigned clock_simulate(unsigned page[], unsigned pagesLen, unsigned tableLen) {

    	printf("\n");
    
    	clock(page, pagesLen, tableLen);
    
    	return 0;


}

void clock(unsigned * pg, unsigned pagesLen, const int frameLen)
{
	int ptr=0;
	int hit;
    	int pageFaultCnt=0;//offset b/c empty buffer isn't a fault
    
    	int * frames = malloc(sizeof(int) * frameLen);
    	for(int j = 0;j < frameLen;j++) {
		
     	   	frames[j]=-1;
    	}
    
    	int * ref = malloc(sizeof(int)*frameLen); // Number of frames 
    	for(int k = 0;k < frameLen;k++) {
	
       	 	ref[k]=0;
	 
    	}
    
    
    
    	int a=0;
    	while(a < pagesLen) { 
	
        	ptr = ptr % frameLen; //reset frame counter at 3 -- like clock

		int page = pg[a]; //Actual page number
        
        	hit = 0;
        	int posi = search_for(&hit, frames, page, frameLen);
			
        	if(hit == REFERED) {
            		if(frames[ptr] != -1)
                		ref[posi] = 1;//When the page is referenced, the use bit is set to 1
            			a++;
        	} else if(hit == NOT_REFERED) {
			
        	
            		if(ref[ptr] == 0) {	
                
                		frames[ptr] = page; 
			
			
                		if(frames[ptr] != -1) {
                    		
					ref[ptr] = 1;
					
				}
                		a++;
                		ptr++;
                		pageFaultCnt++;
				
            		} else if(ref[ptr] == 1) {
			
                		ref[ptr] = 0; //reset bit
                		ptr++;
            		}
            
        	}
        
        	
	}
    
    	
    	printf("\nPage Faults for clock algorithm: %d\n", pageFaultCnt);
	printf("\n-----------------------------------------\n");
    
}

int search_for(int *pgHit, int * frameNum, int pageNum, const int frameLen)
{
    for(int i = 0; i < frameLen; i++)
    {
        if(pageNum == frameNum[i])
        {
            *pgHit = 1;
            return i; 
        }
    }
    return -1;
}
