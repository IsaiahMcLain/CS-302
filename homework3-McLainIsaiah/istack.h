#ifndef ISTACK_H
#define ISTACK_H

/**********************************************
    This is the stack interface which contains all the behaviors 
    a stack should have as determined by the class lecture.  
**********************************************/
template<typename T>
class IStack{
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const T& newEntry) = 0;
    virtual bool pop() = 0;
    virtual T peek() const = 0;
    virtual ~IStack() { }

};

#endif //ISTACK_H