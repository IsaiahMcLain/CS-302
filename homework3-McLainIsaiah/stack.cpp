#include "stack.h"

template<typename T>
Stack<T>::Stack()
    :topPtr{nullptr} {

}

template<typename T>
bool Stack<T>::isEmpty() const{
    return topPtr == nullptr; 
}

template<typename T> 
bool Stack<T>::push(const T& newEntry){
    Node<T>* newNodePtr = new Node<T>(); //Creates new node for new obj 

    //Sets item in node and changes pointer in object to be the top ptr pointing down
    newNodePtr->setItem(newEntry); 
    newNodePtr->setNext(topPtr);

    //Sets topPtr to point towards new obj
    topPtr = newNodePtr;
    newNodePtr = nullptr; 
    return true; 
}

template<typename T>
bool Stack<T>::pop(){
    bool canPop = !isEmpty(); 

    //Tests to see if stack is empty, if not then a node ptr is made
    //That is meant to be deleted and the topptr is suffled to the item
    //below the top item and the top item is removed from the stack
    if(canPop){
        Node<T>* ptrToDelete = topPtr; 
        topPtr = topPtr->getNextPtr();
        delete ptrToDelete; 
        ptrToDelete->setNext(nullptr);
        return true; 
    }
    else{
        return false; 
    }
}

template<typename T>
T Stack<T>::peek() const{
    if(!isEmpty()){
        return topPtr->getItem();
    }
    else{
        throw std::bad_alloc(); 
    }
}

template<typename T>
Stack<T>::~Stack(){
    while(!isEmpty()){
        pop(); 
    }
}