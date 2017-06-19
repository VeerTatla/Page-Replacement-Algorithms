#include <stdio.h>
#include "Optimal.h"
#include "PageReplacement.h"

unsigned optimal_simulate(unsigned pages[], unsigned pages_len, unsigned table_len){

	printf("\n\nrunning OPT simulation\n");
    
    
    	for(int i=0; i<pages_len; i++)
    	{
        	printf("%d ", pages[i]);
    	}
    
    	printf("\n");
    
    	opt(pages, pages_len, table_len);
    
    	return 0;

}

void opt(unsigned reference[], unsigned length, const int frame_size){

	int count[10],i,j,set,cnt,cnt2,cnt3,fcnt,fnd,page_num,max;
	int page_fault=0;
    	int page_frames[10];
	int exist;
	int ptr=0;
	int victim;

	//initilizing distance and frame array	
	for(i=0; i<frame_size; i++)
	{
		page_frames[i]= -1;
	}

	for(j=0; j<length; j++)
	{
		//get current page from the array
		page_num=reference[j];

		//print out every sequence
		printf("\n\n[%d] Page = %d",j+1,page_num);

		//call find function to see if there is any vaule exist in the frame
		exist=exists(frame_size, page_frames, page_num);
		
		//if empty fill the frames
		if (exist==0)
		{
			if(page_frames[ptr] == -1)
			{
				//filling empty frame count as page fault
				page_frames[ptr]=page_num;
				page_fault++;
				ptr++;
				printf("\tEmpty frame is filled by page = %d", page_num);
				//if frame pointer exceed the frame size reset the pointer
				if(ptr==frame_size)
					ptr=0;
			}

			//if frame is full find victim for replacement
			else if(page_frames[ptr] != -1)
			{	
				//set fnd = 0 for case no match
				fnd = 0;
				//reset count array
				for(set=0; set<frame_size; set++)
					count[set] = 0;
			
				//search future pages in reference array
				for(cnt=0; cnt<frame_size; cnt++)
				{
					for(fcnt=j+1; fcnt<length; fcnt++)
					{
						//if find match current page with future page in reference array
						if(page_frames[cnt] == reference[fcnt])
						{
							//set count and break loop
							count[cnt] = fcnt-j;
							break;
						}
					}
				}
				
				//if no match page index found, set victim index for replacement
				for(cnt2=0; cnt2<frame_size; cnt2++)
				{
					if(count[cnt2] == 0)
					{
						victim = cnt2;
						fnd = 1;
						break;
					}
				}
				
				//if all pages are match to refrences replace by in order
				if(fnd == 0)
				{ 
					//set first frame page as max page number
					max = count[0];
					victim = 0;

					//compare with reset of frames
					for(cnt3=1; cnt3<frame_size; cnt3++)
					{
						//if less than the max number set as victim for replacement
						if(max < count[cnt3])
						{
							max = count[cnt3];
							victim = cnt3;
						}
					}
				}
				
				//replace page with OPT page
				printf("\tPage is not available replaced with Page = %d", page_frames[victim]);
				page_frames[victim]=page_num;
				page_fault++;
			}
		}
		else
			printf("\tPage = %d is already in frames", page_num);

		//call display function to print out the result
		display(page_frames, frame_size);
	}

		printf("\n\n************ Total Page Faults: %d ************\n\n", page_fault);

}




