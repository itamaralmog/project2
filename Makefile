
all: mains

mains: main.o libmyBank.a
	gcc -Wall main.o -L. -lmyBank -o mains
	rm my.txt
main.o: main.c
	gcc -Wall -c main.c -o main.o

libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c -o myBank.o

clean:
	rm -f *.o *.a mains
	
.PHONY: all clean
