HW4: main.o event.o
	g++ -g -o HW4 main.o event.o

main.o: main.cpp iqueue.h queue.h priorityqueue.h queue.h
	g++ -g -c main.cpp
	
event.o: event.cpp event.h
	g++ -c event.cpp
	
clean:
	rm *.o HW4