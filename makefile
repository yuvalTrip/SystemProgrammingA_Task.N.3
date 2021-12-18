CC = gcc
FLAGS = -Wall -g
AR= ar


#make all

all: stringProg

stringProg: main.o function.o
	$(CC) main.o function.o -o stringProg

main.o: main.c FuncDef.h
	$(CC) $(FLAGS) -c main.c

function.o: function.c FuncDef.h
	$(CC) $(FLAGS) -c function.c

 #make clean
.PHONY: clean all

 clean:
	rm -f stringProg *.o