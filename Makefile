StrList: Main.o StrList.o
	gcc -Wall -o StrList Main.o StrList.o

Main.o: Main.c StrList.h
	gcc -Wall -c Main.c -o Main.o


StrList.o: StrList.c StrList.h
	gcc -Wall -c StrList.c -o StrList.o

.PHONY: clean all

all: StrList

clean:
	rm -f *.o StrList
