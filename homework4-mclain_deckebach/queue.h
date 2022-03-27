#ifndef QUEUE_H
#define QUEUE_H
#include "iqueue.h"

/**********************************************
    This is the Queue class which is used within the main program
    to create a "line" which customers stay in until the teller is
    ready to serve them. This Queue is implemeted with arrays. 
**********************************************/
template<typename T>
class QUEUE : public IQUEUE<T>{
private:
    static const int DEFAULT_CAPACITY{100}; //Max size of array
    T items[DEFAULT_CAPACITY]; 
    int front{};
    int back{}; 
    int size{};

public:
    QUEUE();
    
    //Sees if queue is empty
    virtual bool isEmpty() const override;

    //Adds item to queue
    virtual bool enqueue(const T& newEntry) override; 
    
    //Removes item from queue
    virtual bool dequeue() override; 
    
    //Returns copy of item at front of queue
    virtual T peekFront() const override; 

    virtual ~QUEUE();  
};

#include "queue.cpp"

#endif //QUEUE_H