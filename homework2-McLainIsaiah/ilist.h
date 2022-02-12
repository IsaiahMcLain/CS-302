#ifndef ILIST_H
#define ILIST_H

/**********************************************
    This is the list interface which contains all the behaviors 
    a list should have as determined by the class lecture.  
**********************************************/
template<typename T>
class IList{
public:
    //Checks to see if list has any items
    virtual bool isEmpty() const = 0; 

    //Checks length of list
    virtual int getLength() const = 0;
    
    //Inserts a new item into the list
    virtual bool insert(int newPos, const T& newEntry) = 0;
    
    //Removes an item from the list
    virtual bool remove(int position) = 0;
    
    //Clears the entire list
    virtual void clear() = 0; 
    
    //Gets an entry from the list and gives it back to the user
    virtual T getEntry(int position) const = 0; 
    
    //Replaces a specifed position within the list with a new item
    virtual T replace(int position, const T& newEntry) = 0;
    
    virtual ~IList() { }
};

#endif //ILIST_H