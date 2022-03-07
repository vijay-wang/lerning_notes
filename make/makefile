OBJS=main.o tool1.o tool2.o
CC=gcc
FLAGS+=-Wall -c -o

mytool:$(OBJS)
	$(CC) $^ -o $@ 

%.o:%.c
	$(CC) $^ $(FLAGS) $@

clean:
	rm *o mytool
