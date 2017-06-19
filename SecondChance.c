#include <stdio.h>
#include "SecondChance.h"
#include "PageReplacement.h"

unsigned second_chance_simulate(unsigned pages[], unsigned pages_len, unsigned table_len) {

	printf("running second chance simulation\n");
    
   
    	for(int i=0; i<pages_len; i++)
    	{
        	printf("%d ", pages[i]);
    	}
    
    	printf("\n");
    
    	second_chance(pages, pages_len, table_len);
    
    	return 0;



}

void second_chance(unsigned * pg, unsigned pages_len, const int frame_len) {

	// Need to finish this part here!

}
