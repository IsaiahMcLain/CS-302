#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<string>

/**********************************************
    This is the Node class which is used in tandem with the stack
    to store objects. It contains the object for the stack as well
    as it's assigned pointer so that the user can link the stack.  
**********************************************/
template<typename T> 
class Node{
private:
    T item; //Data item
    Node<T>* next; //Pointer within node that pts to next item
public:
    Node();
    Node(const T& newItem, Node<T>* nextNodePtr);
    
    //Sets item attribute
    void setItem(const T& newItem);
    
    //Sets pointer attribute that points to node
    void setNext(Node<T>* nextNodePtr);
    
    //Returns item
    T getItem() const;
    
    //Returns pointer of node pointing to next object
    Node<T>* getNextPtr() const; 
};

#include "node.cpp"

#endif //NODE_H