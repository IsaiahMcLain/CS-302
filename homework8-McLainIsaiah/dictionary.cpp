#include "dictionary.h"

template<typename keyType, typename valueType>
DICTIONARY<keyType, valueType>::DICTIONARY(){
    
}

template<typename keyType, typename valueType>
bool DICTIONARY<keyType, valueType>::isEmpty() const{
    return entryTree.isEmpty();
}

template<typename keyType, typename valueType>
bool DICTIONARY<keyType, valueType>::contains(const keyType& targetKey) const{
    return entryTree.contains(targetKey); 
}

template<typename keyType, typename valueType>
bool DICTIONARY<keyType, valueType>::add(const keyType& newKey, const valueType& newValue){
    ENTRY<keyType, valueType>  newEntry(newKey, newValue); 

    if(!entryTree.contains(newEntry)){
        return entryTree.add(newEntry);
    }
    
    return false; 
}

template<typename keyType, typename valueType>
bool DICTIONARY<keyType, valueType>::remove(const keyType& targetKey){

    if(!entryTree.contains(targetKey)){
        return false;
    }
    else{
        entryTree.remove(targetKey);
    }
}

template<typename keyType, typename valueType>
void DICTIONARY<keyType, valueType>::clear(){
    entryTree.clear();
}

template<typename keyType, typename valueType>
valueType DICTIONARY<keyType, valueType>::getValue(const keyType& targetKey) const{
    if(entryTree.contains(targetKey)){
        LinkedBTreeNode<keyType>* keyPtr = targetKey; 
        return entryTree.findNode(keyPtr, targetKey); 
    }

    return false; 
}

template<typename keyType, typename valueType>
DICTIONARY<keyType, valueType>::~DICTIONARY(){
    entryTree.clear();
}


