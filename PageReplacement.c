/*
* Veer Tatla cssc1153
* Josh Robey cssc1126
* CS570 Assignment 2
* PageReplacement.c
*
* This program runs the main method which provides a function
* that leads to the different page replacement algorithms 
* passing in the neccessary parameters. This program also
* tokenizes the integer values from "pages.txt".
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PageReplacement.h"
#include "Clock.h"
#include "Optimal.h"
#include "SecondChance.h"
#define PAGE_TABLE_LENGTH 3

unsigned read_page_file(unsigned (*pages_ptr)[]){

	FILE * fp = fopen("pages.txt", "r");
	
	char buff[4096];
	int len = fread(buff, 1, sizeof(buff), fp);
	
	unsigned pages_len = (len/2) + 1;
	unsigned pages[pages_len];
	
	char * pch;
	
	pch = strtok (buff," ");
    	int i=0;
    	while (pch != NULL)
    	{

        	unsigned page = atoi(pch);
        	pages[i++]=page;
        	pch = strtok (NULL, " ");
    	}
    
    	for(int j = 0;j < pages_len;j++)
    	{

        	(*pages_ptr)[j] = pages[j];
    	}
    
    
    	return i;

}


int exists(int frame_size,int page_frames[],int page_num)
{
    	int i, located = 0;
    
    	//search frame
    	for (i = 0;i < frame_size;i++) {
    	
		if(page_frames[i] == page_num) {
            
	    		located = 1;
	    
	    		}
	    
    		}
    
    	return located;
}





void page_replacement_sim(){

	int page_tab_len = PAGE_TABLE_LENGTH;
	printf("\n Enter page file length: ");
	scanf("%d", &page_tab_len);
	
	unsigned _pages[100];
	
	int length = read_page_file(&_pages);
	
	printf("\nPage sequence being tested: ");
    	for(int j=0; j<length; j++)
    	{
        	printf("%d ", _pages[j]);
    	}
	
	clock_simulate(_pages, length, page_tab_len);
	
	optimal_simulate(_pages, length, page_tab_len);
	
	second_chance_simulate(_pages, length, page_tab_len);

}


int main(int argc, const char * argv[]){

	page_replacement_sim();
	
	return 0;	

}
