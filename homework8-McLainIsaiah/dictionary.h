#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "idictionary.h"
#include "entry.h"
#include "linkedbtree.h"

/**********************************************
    This class is used to implement the dictionary data structure. It inherits
    from the interface and is implemented using a binary search tree. The reason I
    went with this implementation is because the BST will do most
    of the heavy lifting for us making it easier to implment the functions. It 
    also is the fastest way to implement a dictionary in terms of time complextiy. 
**********************************************/
template<typename keyType, typename valueType>
class DICTIONARY: public IDICTIONARY<keyType, valueType>{
private:
    LinkedBTree<ENTRY<keyType, valueType>> entryTree; 
    
public:
    DICTIONARY();

    virtual bool isEmpty() const override;
    virtual bool add(const keyType& newKey, const valueType& newValue) override;
    virtual bool remove(const keyType& targetKey) override;
    virtual void clear() override;
    virtual bool contains(const keyType& targetKey) const override;
    virtual valueType getValue(const keyType& targetKey) const override;
    virtual ~DICTIONARY();
};

#include "dictionary.cpp"

#endif //DICTIONARY_H