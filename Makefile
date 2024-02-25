Main: main.o StrList.o
	gcc -Wall -o Main main.o StrList.o

main.o: main.c StrList.h
	gcc -Wall -c main.c -o main.o


StrList.o: StrList.c StrList.h
	gcc -Wall -c StrList.c -o StrList.o

.PHONY: clean all

all: Main

clean:
	rm -f *.o Main
