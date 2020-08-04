all: run-mq

run-mq: MinQueue-main.o 
	c++ -std=c++11 MinQueue-main.o -o run-mq

MinQueue-main.o: MinQueue-main.cpp MinQueue.h TemplatedDLList.h
	c++ -std=c++11 -c MinQueue-main.cpp

clean:
	rm *.o run-mq
