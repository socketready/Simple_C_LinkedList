cc=gcc
flags=-g

LinkedListTester: LinkedListTester.c LinkedList.o LinkedList.h
	$(cc) $(flags) -o LinkedListTester LinkedListTester.c LinkedList.o

LinkedList.o: LinkedList.c LinkedList.h
	$(cc) $(flags) -c LinkedList.c

clean:
	rm *.o
