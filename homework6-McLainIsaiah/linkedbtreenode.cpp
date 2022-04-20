#include "linkedbtreenode.h"

template<typename T>
LinkedBTreeNode<T>::LinkedBTreeNode()
    :item{0}, leftChildPtr{nullptr}, rightChildPtr{nullptr} {

}

template<typename T> 
LinkedBTreeNode<T>::LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right)
    :item{newData}, leftChildPtr{left}, rightChildPtr{right} {

}

template<typename T> 
void LinkedBTreeNode<T>::setItem(const T& newData){
    item = newData; 
}

template<typename T>
T LinkedBTreeNode<T>::getItem() const{
    return item; 
}

template<typename T>
bool LinkedBTreeNode<T>::isLeaf() const{
    if(leftChildPtr == nullptr && rightChildPtr == nullptr){
        return true; 
    }

    return false; 
}

template<typename T> 
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getLeftChildPtr() const{
    return leftChildPtr; 
}

template<typename T> 
LinkedBTreeNode<T>* LinkedBTreeNode<T>::getRightChildPtr() const{
    return rightChildPtr; 
}

template<typename T>
void LinkedBTreeNode<T>::setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr){
    leftChildPtr = newLeftChildPtr; 
}

template<typename T>
void LinkedBTreeNode<T>::setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr){
    rightChildPtr = newRightChildPtr; 
}

template<typename T>
LinkedBTreeNode<T>::~LinkedBTreeNode(){
    leftChildPtr = nullptr;
    rightChildPtr = nullptr; 
}