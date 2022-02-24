#ifndef STACK_H
#define STACK_H
#include<iostream>
#include<string>
#include "node.h"
#include "istack.h"

/**********************************************
    This is the Stack class which is used within the main program
    to work with postfix notation and calculations. The stack is
    implemented in a linked fashion.  
**********************************************/
template<typename T>
class Stack: public IStack<T>{
private:
    Node<T>* topPtr;

public: 
    Stack(); 

    //Sees if stack is empty
    virtual bool isEmpty() const override;

    //Adds new entry to top of stack
    virtual bool push(const T& newEntry) override;
    
    //Removes top entry from stack
    virtual bool pop() override;
    
    //Returns COPY of top item in stack
    virtual T peek() const override;
    virtual ~Stack(); 

};

#include "stack.cpp"

#endif //STACK_H