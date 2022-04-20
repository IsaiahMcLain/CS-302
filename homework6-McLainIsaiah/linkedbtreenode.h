#ifndef LINKEDBTREENODE_H
#define LINKEDBTREENODE_H

/**********************************************
    This class is used to create nodes for the tree. For our program, 
    since we are using a Binary Search Tree each node can have two children
    which is indicated by the two pointer attributes, as well as a data item the 
    node is storing.  
**********************************************/
template<typename T>
class LinkedBTreeNode{
private:
    T item;
    LinkedBTreeNode<T>* leftChildPtr;
    LinkedBTreeNode<T>* rightChildPtr; 

public:
    LinkedBTreeNode();
    LinkedBTreeNode(const T& newData, LinkedBTreeNode<T>* left, LinkedBTreeNode<T>* right);

    void setItem(const T& newData);
    T getItem() const;

    //Determines if a node is a leaf (no children) or not
    bool isLeaf() const;

    LinkedBTreeNode<T>* getLeftChildPtr() const;
    LinkedBTreeNode<T>* getRightChildPtr() const; 

    void setLeftChildPtr(LinkedBTreeNode<T>* newLeftChildPtr);
    void setRightChildPtr(LinkedBTreeNode<T>* newRightChildPtr); 

    ~LinkedBTreeNode();
};

#include "linkedbtreenode.cpp"

#endif //LINKEDBTREENODE_H