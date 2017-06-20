/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* Optimal.c
*
* This program runs the Optimal page replacement algorithm. 
*/
#include <stdio.h>
#include "Optimal.h"
#include "PageReplacement.h"

unsigned optimal_simulate(unsigned page[], unsigned pagesLen, unsigned tableLen){
	
	
    	printf("\n");
    
    	opt(page, pagesLen, tableLen);
    
    	return 0;

}

void opt(unsigned reference[], unsigned length, const int frame_size){

	int countArr[10], j, k, set, count, count2, count3, fcount, find, page_num, max;
	int page_fault=0;
    	int page_frames[10];
	int exist;
	int ptr=0;
	int victim;

	//Initialzes distance and page frame array.	
	for(j = 0; j < frame_size; j++)
	{
		page_frames[j] = -1;
	}

	for(k = 0; k < length; k++)
	{
		
		page_num=reference[k];

		//Check for page hit in exists function.
		exist = exists(frame_size, page_frames, page_num);
		
		// Fill empty frames
		if (exist == 0)
		{
			if(page_frames[ptr] == -1)
			{
				
				page_frames[ptr] = page_num;
				page_fault++;
				ptr++;
				
				// Reset pointer when necessary.
				if(ptr == frame_size) {
					ptr = 0;
				}
			}

			// Find victim for replacement
			else if(page_frames[ptr] != -1)
			{	
				find = 0;
				for(set = 0; set < frame_size; set++)
					countArr[set] = 0;
			
				
				for(count = 0; count < frame_size; count++)
				{
					for(fcount = k+1; fcount < length; fcount++)
					{
						
						if(page_frames[count] == reference[fcount])
						{
							
							countArr[count] = fcount-k;
							break;
						}
					}
				}
				
				
				for(count2 = 0; count2 < frame_size; count2++)
				{
					if(countArr[count2] == 0)
					{
						victim = count2;
						find = 1;
						break;
					}
				}
				
				
				if(find == 0)
				{ 
					
					max = countArr[0];
					victim = 0;

					
					for(count3 = 1; count3 < frame_size; count3++)
					{
						
						if(max < countArr[count3])
						{
							max = countArr[count3];
							victim = count3;
						}
					}
				}
				
				
				page_frames[victim] = page_num;
				page_fault++;
			}
		}
		
			
	}

		printf("\nPage faults for Optimal algorithm: %d\n", page_fault);
		printf("\n-----------------------------------------\n");
    

}




