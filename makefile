CC = gcc
 FLAGS = -Wall -g
 AR= ar


 #make all
all:mains maindloop maindrec


#make clean
.PHONY: clean all

 clean: 
	rm -f mains maindrec maindloop *.a *.so *.o
