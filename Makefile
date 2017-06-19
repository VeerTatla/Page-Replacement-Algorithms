all:
	gcc -o a2 --std=gnu99  PageReplacement.c Clock.c Optimal.c SecondChance.c
clean:
	rm a2
run:
	./a2
