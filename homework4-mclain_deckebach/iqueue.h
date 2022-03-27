#ifndef IQUEUE_H
#define IQUEUE_H
#include <string>
#include <iostream> 

/**********************************************
    This is the queue interface which contains all the behaviors 
    a queue should have as determined by the class lecture.  
**********************************************/
template<typename T> 
class IQUEUE{
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const T& newEntry) = 0; 
    virtual bool dequeue() = 0; 
    virtual T peekFront() const = 0; 

    virtual ~IQUEUE() {}  
};

#endif //IQUEUE_H