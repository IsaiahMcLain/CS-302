#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "iqueue.h"

/**********************************************
    This is the PriorityQueue class which is used within the main program
    to create an event based datastructure which is used to keep track of
    customers arrival and departure times with the earliest customer 
    arrival being in the front and the lastest customer arrival being at
    the end. Customers that depart from the line (leave) are dequeued. 
**********************************************/
template<typename T>
class PRIORITYQUEUE: public IQUEUE<T>{
private:
    static const int DEFAULT_CAPACITY{100};
    T items[DEFAULT_CAPACITY]; 
    int front{};
    int back{}; 
    int size{};

public:
    PRIORITYQUEUE();
    virtual bool isEmpty() const override;

    //This funcion differs from Queue as it must organize array
    //by priority (arrival time) in circular fashion
    virtual bool enqueue(const T& newEntry) override; 
    virtual bool dequeue() override; 
    virtual T peekFront() const override; 

    virtual ~PRIORITYQUEUE();  
};

#include "priorityqueue.cpp"

#endif //PRIORITYQUEUE_H