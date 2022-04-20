#include "linkedbtree.h"

template<typename T> 
LinkedBTree<T>::LinkedBTree()
    :rootPtr{nullptr} {

}

template<typename T>
bool LinkedBTree<T>::isEmpty() const{
    if(rootPtr == nullptr){
        return true;
    }
    return false; 
}

template<typename T>
int LinkedBTree<T>::getHeight() const{
    if(rootPtr == nullptr){
        return 0; 
    }
    else{
        return getHeightHelper(rootPtr); //Needed to start recursion 
    }
}

template<typename T>
int LinkedBTree<T>::getNumberOfNodes() const{
    if(rootPtr == nullptr){
        return 0; 
    }
    else{
        return getNumberNodesHelper(rootPtr); //Needed to start recursion
    }
}

template<typename T>
T LinkedBTree<T>::getRootData() const{
  return rootPtr->getItem();   //Accesses attribute rootPtr's data (item stored in node)
}

/**********************************************
    This function is mainly used to start the recursion needed
    to add an item to the tree, however it does make a new node object
    and puts the item into the node before starting the recursion.
    @param const T& newEntry
    @return bool, tells if add was successful or not
**********************************************/
template<typename T>
bool LinkedBTree<T>::add(const T& newEntry){
    LinkedBTreeNode<T>* newNodePtr = new LinkedBTreeNode<T>(); //Default Constructor
    newNodePtr->setItem(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true; 
}

/**********************************************
    This function is mainly used to start the recursion needed
    to remove an item from the tree. 
    @param const T& anEntry
    @return bool, tells if remove was successful or not
**********************************************/
template<typename T>
bool LinkedBTree<T>::remove(const T& anEntry){
    bool isSuccessful = false; 
    rootPtr = removeValue(rootPtr, anEntry, isSuccessful);
    return isSuccessful; 
}

/**********************************************
    This function is needed as the clear function cannot destroy the
    tree by itself and needs to start a recursive function, which is
    what this function is. It recursively access the children of the treePtr
    starting from the root ptr and once it gets to the leafs it pops of the
    stack deleting every ptr and object. 
    @param LinkedBTreeNode<T>* treePtr
    @return void (none)
**********************************************/
template<typename T>
void LinkedBTree<T>::destroyTree(LinkedBTreeNode<T>* treePtr){
    if(treePtr != nullptr){
        destroyTree(treePtr->getLeftChildPtr()); //Needed before delete so there is no memory leak
        destroyTree(treePtr->getRightChildPtr());
        delete treePtr;
        treePtr = nullptr; 
    }
}

template<typename T>
void LinkedBTree<T>::clear(){
        destroyTree(rootPtr);
}

/**********************************************
    This function just returns a boolean value if the item within 
    the tree is in the tree or not. (Think getEntry but returns a bool instead)
    @param const T& anEntry
    @return bool, tells if item in tree exists or not
**********************************************/
template<typename T>
bool LinkedBTree<T>::contains(const T& anEntry) const{
    bool isSuccessful = false; 
    findNode(rootPtr, anEntry); 
    return isSuccessful;

}

/**********************************************
    This function is the recursive implemetation of preorder algorithim
    to traverse a tree. It vists the root and then all the left items of the
    left subtree then all the right items of the left subtree and does the vice versa
    for the right subtree. Visit function here is the display function in main.
    @param void visit(T&), LinkedBTreeNode<T>* treePtr
    @return none (void)
**********************************************/
template<typename T>
void LinkedBTree<T>::preorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        T item = treePtr->getItem(); 
        visit(item); 

        preorder(visit, treePtr->getLeftChildPtr()); //Occurs after item is retrieved due to order
        preorder(visit, treePtr->getRightChildPtr()); 
    }
}

/**********************************************
    This function is the implementaion of the inorder recursion traversal.
    Works much like the preorder except the order is changed since this traversal
    starts with the left most subtree item and then goes inorder through the
    tree. 
    @param void visit(T&), LinkedBTreeNode<T>* treePtr
    @return void(none)
**********************************************/
template<typename T>
void LinkedBTree<T>::inorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        inorder(visit, treePtr->getLeftChildPtr()); //Recursion causes entire left subtree to be seen first

        T item = treePtr->getItem();
        visit(item); 

        inorder(visit, treePtr->getRightChildPtr()); //Then entire right subtree
    }
}

/**********************************************
    This function is the implementaion of the postorder recursion. It works
    the same way as the other two except the function calls are placed first in the
    function with the left subtree being accessed first as post order goes left 
    then right and so on up the left subtree and then does it again for the
    right subtree. (ends at root) 
    @param void visit(T&), LinkedBTreeNode<T>* treePtr
    @return void(none)
**********************************************/
template<typename T>
void LinkedBTree<T>::postorder(void visit(T&), LinkedBTreeNode<T>* treePtr) const{
    if(treePtr != nullptr){
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());

        T item = treePtr->getItem();
        visit(item); 
    }
}

template<typename T>
void LinkedBTree<T>::preorderTraverse(void visit(T&)) const{
    preorder(visit, rootPtr);
}

template<typename T>
void LinkedBTree<T>::inorderTraverse(void visit(T&)) const{
    inorder(visit, rootPtr);
}

template<typename T>
void LinkedBTree<T>::postorderTraverse(void visit(T&)) const{
    postorder(visit, rootPtr);
}

/**********************************************
    This function implements the recursion needed to actually
    place a new node within the tree. 
    @param LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* subTreePtr
    @return LinkedBTreeNode<T>* subTreePtr, returns ptr to where item was added
**********************************************/
template<typename T>
LinkedBTreeNode<T>* LinkedBTree<T>::placeNode(LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* newNodePtr){
    LinkedBTreeNode<T>* tempPtr;
    if(subTreePtr == nullptr){
        return newNodePtr; 
    }
    //If the item of the subtree is greater than new item, recursively access the left subtree
    //Until case is met where node is added. Same goes for else statement but for right subtree.
    else if(subTreePtr->getItem() > newNodePtr->getItem()){
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr); 
    }
    else{
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr); 
    }
    return subTreePtr;
}

/**********************************************
    This function implements the recursion needed to actually
    remove a node from the tree. 
    @param LinkedBTreeNode<T>* subTreePtr, const T& target, bool& isSuccessful
    @return LinkedBTreeNode<T>* subTreePtr, returns ptr to where item was removed
**********************************************/
template<typename T>
LinkedBTreeNode<T>* LinkedBTree<T>::removeValue(LinkedBTreeNode<T>* subTreePtr, const T target, bool& isSuccessful){
   LinkedBTreeNode<T>* tempPtr;
   if(subTreePtr == nullptr){
       isSuccessful = false; 
   } 
   //If target is found, item to be removed, call removeNode func and end recursion
   else if(subTreePtr->getItem() == target){
       subTreePtr = removeNode(subTreePtr);
       isSuccessful = true; 
   }
   //Determines which part of tree we should traverse (left in this case) to find target
   //Same is for else statement but goes right instead of left
   else if(subTreePtr->getItem() > target){
       tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
       subTreePtr->setLeftChildPtr(tempPtr);
   }
   else{
       tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
       subTreePtr->setRightChildPtr(tempPtr);
   }
   return subTreePtr; 
}

/**********************************************
    This function implements the recursion needed to actaully
    remove a node within the tree and contains the logic needed to deal with
    the three cases that may occur when removing a node. 
    @param LinkedBTreeNode<T>* nodePtr
    @return LinkedBTreeNode<T>* nodePtr (or nodeToConnect), returns ptr to where item was removed and where to link children
**********************************************/
template<typename T>
LinkedBTreeNode<T>* LinkedBTree<T>::removeNode(LinkedBTreeNode<T>* nodePtr){
    LinkedBTreeNode<T>* tempPtr; 
    LinkedBTreeNode<T>* nodeToConnect; 
    //If the removal is a leaf, as easy as deleting the leaf
    if(nodePtr->isLeaf()){
            delete nodePtr;
            nodePtr = nullptr;
            return nodePtr; 
    }
    //If node has one child, must detemine whether left or right child and then reuturns that child to be placed in place of parent
    else if(nodePtr->isLeaf() == false && (nodePtr->getLeftChildPtr() == nullptr || nodePtr->getRightChildPtr() == nullptr)){
        if(nodePtr->getLeftChildPtr() != nullptr)
            nodeToConnect = nodePtr->getLeftChildPtr();
        else 
            nodeToConnect = nodePtr->getRightChildPtr(); 
        return nodeToConnect;
    }
    //If node has two children this else statement calls another recursive function to handle the logic
    //Needed to determine which child replaces parent and where the second child should fall
    //within the tree
    else{
        T newNodeValue;
        tempPtr = removeLeftMostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue);
        return nodePtr; 
    }

}

/**********************************************
    This function implements the recursion needed to actaully
    handle the case of removing a node within the tree that has 2 children
    @param LinkedBTreeNode<T>* subTreePtr, LinkedBTreeNode<T>* subTreePtr
    @return LinkedBTreeNode<T>* nodePtr (or function call to removeNode), returns ptr to where child needs to be placed
**********************************************/
template<typename T>
LinkedBTreeNode<T>* LinkedBTree<T>::removeLeftMostNode(LinkedBTreeNode<T>* nodePtr, T& inorderSuccessor){
    LinkedBTreeNode<T>* tempPtr; 
    
    //Determines that the function is finally at the far left child and initaiates replacement
    if(nodePtr->getLeftChildPtr() == nullptr){
        inorderSuccessor = nodePtr->getItem(); 
        return removeNode(nodePtr); 
    }
    //Recursively access left most children until it reaches leftmost child
    else{
        tempPtr = removeLeftMostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
        nodePtr->setLeftChildPtr(tempPtr);
        return nodePtr; 
    }
}

/**********************************************
    This function implements the recursion needed to find a node within the tree
    and return that node to it's callee function. 
    @param LinkedBTreeNode<T>* TreePtr, const T& target
    @return LinkedBTreeNode<T>* TreePtr, returns ptr to item location or function call to itself for recursion
**********************************************/
template<typename T>
LinkedBTreeNode<T>* LinkedBTree<T>::findNode(LinkedBTreeNode<T>* treePtr, const T& target) const{
    if(treePtr == nullptr){
        return nullptr; 
    }
    //Reuturn location of target
    else if(treePtr->getItem() == target){
        return treePtr; 
    }
    //Scans left subtree if target is less than parent node
    else if(treePtr->getItem() > target){
        return findNode(treePtr->getLeftChildPtr(), target);
    }
    //Otherwise scans right subtree
    else
        return findNode(treePtr->getRightChildPtr(), target); 
}

template<typename T>
LinkedBTree<T>::~LinkedBTree(){
    clear(); 
}

/**********************************************
    This function implements the recursion needed to count the number of nodes.  
    @param LinkedBTreeNode<T>* rootPtr
    @return int numberOfNodes
**********************************************/
template<typename T>
int LinkedBTree<T>::getNumberNodesHelper(LinkedBTreeNode<T>* rootPtr) const{
    //Base case, when child is null stop counting
    if(rootPtr == nullptr){
        return 0; 
    }
    //Adds up rootPtr of subtree then traverses subtree recursively to get total number of nodes
    else{
        return 1 + getNumberNodesHelper(rootPtr->getLeftChildPtr()) + getNumberNodesHelper(rootPtr->getRightChildPtr());
    }
}

/**********************************************
    This function implements the recursion needed to get the height of the tree.  
    @param LinkedBTreeNode<T>* rootPtr
    @return int numberOfNodes
**********************************************/
template<typename T>
int LinkedBTree<T>::getHeightHelper(LinkedBTreeNode<T>* rootPtr) const{
    //Base case, doesn't add anymore to the height
    if(rootPtr == nullptr){
        return 0; 
    }
    //Much like numberOfNodes it traverses the subtrees of the "rootPtr" (parent node passed into function)
    //However, the std::max function only returns which subtree had a greater number of nodes, in this case
    //that is the max height of the tree
    else{
        return 1 + std::max(getHeightHelper(rootPtr->getLeftChildPtr()), getHeightHelper(rootPtr->getRightChildPtr()));
    }
}