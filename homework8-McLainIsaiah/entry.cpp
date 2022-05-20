#include "entry.h"

template<typename keyType, typename valueType>
ENTRY<keyType, valueType>::ENTRY(){

}

template<typename keyType, typename valueType>
ENTRY<keyType, valueType>::ENTRY(const keyType& newKey, const valueType& newValue)
    :key{newKey}, value{newValue}{

}

template<typename keyType, typename valueType>
valueType ENTRY<keyType, valueType>::getValue() const{
    return value;
}

template<typename keyType, typename valueType>
keyType ENTRY<keyType, valueType>::getKey() const{
    return key; 
}

template<typename keyType, typename valueType>
void ENTRY<keyType, valueType>::setValue(const valueType& newValue){
    value = newValue;
}

template<typename keyType, typename valueType>
void ENTRY<keyType, valueType>::setKey(const keyType& newKey){
    key = newKey;
}

template<typename keyType, typename valueType>
bool ENTRY<keyType, valueType>::operator==(const ENTRY<keyType, valueType>& rhs) const{
    return this->getKey() == rhs.getKey(); 
}

template<typename keyType, typename valueType>
bool ENTRY<keyType, valueType>::operator>(const ENTRY<keyType, valueType>& rhs) const{
    return this->getKey() > rhs.getKey(); 
}


