#include "todolist.h"

template<typename T>
ToDoList<T>::ToDoList()
    :itemCount{0}, headPtr{nullptr} {

}

/**********************************************
    This function first checks to make sure the user inserted position isn't 
    beyond the linked list's items. It then uses a Node ptr to track each ptr
    to it's next node until it arrives at the ptr pointing to the next object
    it wants. It will then return said ptr to whatever function called it. 
    @param int position
    @return Node<T>* 
**********************************************/
template<typename T>
Node<T>* ToDoList<T>::getNodeAt(int position) const{
    bool canGet = (position <= itemCount) && (position >= 1); 

    if(canGet){
        Node<T>* ptrTracker = headPtr; 
        
        for(int i = 1; i < position; i++){
            ptrTracker = ptrTracker->getNextPtr();
        }
        return ptrTracker; 
    }
    else{
        return nullptr; 
    }
}

template<typename T>
int ToDoList<T>::getLength() const{
    return itemCount; 
}

template<typename T>
bool ToDoList<T>::isEmpty() const{
    return itemCount == 0; 
}

template<typename T>
void ToDoList<T>::clear() {
    //Uses other function calls to do most of the work
    while(!isEmpty()){
        remove(1);
    }
}

/**********************************************
    This function first checks to make sure that a new item can be added
    to the list. If it can then a new node object is created and the 
    newEntry item is put into the node. Using if/else logic the function
    determines whether or not the item will be the first item inserted or not. 
    Based off either case the logic is executed and adds an item to the list and
    increases item count. 
    @param int newPos, const T& newEntry
    @return bool
**********************************************/
template<typename T>
bool ToDoList<T>::insert(int newPos, const T& newEntry){
    bool canAdd = (newPos >= 1) && (newPos <= itemCount + 1);

    if(canAdd){
        Node<T>* newNodePtr = new Node<T>(); //Calls node constructor

        newNodePtr->setItem(newEntry); //Adds entry to node but not a ptr value yet
        
        //Determines if this will be first entry in list, if so simply assign the new node's ptr value to be headptr value of list
        //and vice versa so the node and the class know the headptr's address location
        if(newPos == 1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr; 
        }
        else{
            Node<T>* prevPtr = getNodeAt(newPos - 1); //Must subtract by 1 to get node before node we want
            //Sets newNodePtr to the value of the ptr the previous ptr is pointing to
            //This prevents loss of second half of list in case that object is being inserted in the middle
            newNodePtr->setNext(prevPtr->getNextPtr()); 
            //newNodePtr = prevPtr->getNextPtr();  causes seg fault
            prevPtr->setNext(newNodePtr); //Sets previous ptr to point to the new node, completing the linked list
        } 
    itemCount++;   
    }
    return canAdd; 
}

/**********************************************
    This function first checks to make sure that the item can be removed
    and is not out of bounds of the list. Then goes through if/else logic 
    to determine what object is being removed. 
    @param int position
    @return bool
**********************************************/
template<typename T>
bool ToDoList<T>::remove(int position){
    bool canRemove = (position >= 1) && (position <= itemCount); 

    if(canRemove){
        Node<T>* toDeletePtr = headPtr; //Starts ptr off at start of list
        //If removing first object, just need to reassign headptr to point to object after first obj
        if(position == 1){
            headPtr = headPtr->getNextPtr(); 
        }
        else{
            Node<T>* prevPtr = getNodeAt(position - 1); //subtract 1 as we want previous pointer from stated pos
            toDeletePtr = prevPtr->getNextPtr(); //Sets deleteptr = to the node object we want to remove
            //Prevents seg fault by relinking list, prev ptr now points to obj after deleteptr
            prevPtr->setNext(toDeletePtr->getNextPtr()); 
            
        }
        delete toDeletePtr; 
        toDeletePtr = nullptr; //Prevents free floating node and releases memory
        itemCount--;
    }
    return canRemove; 
}

/**********************************************
    This function first checks to make sure that the item can be 
    retrieved from the list. It then will get the item and use getItem()
    function from Node class to return the item within the node and list. 
    @param int position
    @return T item->getItem()
**********************************************/
template<typename T>
T ToDoList<T>::getEntry(int position) const{
    bool canGet = (position >= 1) && (position <= itemCount);
    
    if(canGet){
        Node<T>* item = getNodeAt(position);
        return item->getItem();
    } 
    else{
        std::string message{"Error, position entered invalid. Make sure the number is within the current size of list. Please try again"};
        return message; 
    }
    
}

/**********************************************
    This function first checks to make sure that the item in the list 
    can be replaced. It then creates a new Node called olditem which stores
    the old item and it's ptr. Using the insert function we put the new item in it's 
    place and return the olditem's item. 
    @param int position, const T& newEntry
    @return T Olditem->getItem()
**********************************************/
template<typename T>
T ToDoList<T>::replace(int position, const T& newEntry){
    bool canReplace = (position >= 1) && (position <= itemCount); 
    
    if(canReplace){
        Node<T>* oldItem = getNodeAt(position);
        insert(position, newEntry); 
        return oldItem->getItem(); 
    }
    else{
        std::string message{"Error, position entered invalid. Make sure the number is within the current size of the list. Please try again."};
        return message; 
    }

}

template<typename T>
ToDoList<T>::~ToDoList(){
    clear();
}
