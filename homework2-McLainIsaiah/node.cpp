#include "node.h"

template<typename T>
Node<T>::Node() 
    :next{nullptr} {

}

template<typename T>
Node<T>::Node(const T& newItem, Node<T>* nextNodePtr)
    :item{newItem}, next{nextNodePtr} {

}

template<typename T> 
void Node<T>::setItem(const T& newItem){
    item = newItem; 
}

template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr){
    next = nextNodePtr;
}

template<typename T>
T Node<T>::getItem() const{
    return item; 
}

template<typename T>
Node<T>* Node<T>::getNextPtr() const{
    return next; 
}