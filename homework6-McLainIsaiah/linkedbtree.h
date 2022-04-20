#ifndef LINKEDBTREE_H
#define LINKEDBTREE_H

#include "itree.h"
#include "linkedbtreenode.h"
#include <algorithm> //Used for std::max function 

/**********************************************
    This class directly inherits from the ITree interface. In a normal case
    we would inherit from a BinaryTree class that inherited the interface and this class
    would inherit from the BinaryTree class, however, due to time contraints and
    complexity, this class directly inherits from the interface and implements 
    protected functions that would've been inherited from the Binary Tree class if it was
    implemented.   
**********************************************/
template<typename T> 
class LinkedBTree: public ITree<T>{
private:
    LinkedBTreeNode<T>* rootPtr;

//Helper Functions (would come from Binary Tree Class)
protected: 
    LinkedBTreeNode<T>* placeNode(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr);
    LinkedBTreeNode<T>* removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessful);
    LinkedBTreeNode<T>* removeNode(LinkedBTreeNode<T>* nodePtr);
    LinkedBTreeNode<T>* removeLeftMostNode(LinkedBTreeNode<T>* nodePtr, T& inorderSuccessor); 
    LinkedBTreeNode<T>* findNode(LinkedBTreeNode<T>* treePtr, const T& target) const; 
    int getHeightHelper(LinkedBTreeNode<T>* rootPtr) const;
    int getNumberNodesHelper(LinkedBTreeNode<T>* rootPtr) const;
    void preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
    void inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
    void postorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const;
    void destroyTree(LinkedBTreeNode<T>* treePtr);

public:
    LinkedBTree();

    virtual bool isEmpty() const override; 
    virtual int getHeight() const override; 
    virtual int getNumberOfNodes() const override;
    virtual T getRootData() const override;
    virtual bool add(const T& newEntry) override;
    virtual bool remove(const T& anEntry) override;
    virtual void clear() override;
    virtual bool contains(const T& anEntry) const override;

    //Tree Traversal Functions 
    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const; 

    virtual ~LinkedBTree(); 
};

#include "linkedbtree.cpp"

#endif //LINKEDBTREE_H