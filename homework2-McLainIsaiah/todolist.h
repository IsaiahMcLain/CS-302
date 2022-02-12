#ifndef TODOLIST_H
#define TODOLIST_H
#include "ilist.h"
#include "node.h"

/**********************************************
    This is the ToDoList class which is the implemention of the data
    structure list. It contains a headptr which is used to track the entire
    lists location, an itemcount to keep track of the amount of items in the 
    list. 
**********************************************/
template<typename T> 
class ToDoList: public IList<T>{
private:
    Node<T>* headPtr; 
    int itemCount; 

    //Reduces code reuse and returns node at position 
    Node<T>* getNodeAt(int position) const; 
public:
    ToDoList(); 

    virtual bool isEmpty() const override; 
    virtual int getLength() const override;
    virtual bool insert(int newPos, const T& newEntry) override;
    virtual bool remove(int position) override;
    virtual void clear() override; 
    virtual T getEntry(int position) const override; 
    virtual T replace(int position, const T& newEntry) override;

    virtual ~ToDoList(); 
};

#include "todolist.cpp"

#endif //TODOLIST_H