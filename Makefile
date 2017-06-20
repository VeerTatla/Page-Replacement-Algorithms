#########################################
# Veer Tatla cssc1153			#
# Josh Robey cssc1126			#
# CS570 Assignment 2			#
# Makefile				#
#					#
# This is make file for entire program. # 
#					#
#########################################

all:
	gcc -o a2 --std=gnu99  PageReplacement.c Clock.c Optimal.c SecondChance.c
clean:
	rm a2
run:
	./a2
