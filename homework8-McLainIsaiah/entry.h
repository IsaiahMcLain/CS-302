#ifndef ENTRY_H
#define ENTRY_H

/**********************************************
    This class is used to create entires for the dictionar. For a dictionary
    to work we need a key and value and therefore two templated varaibles 
    in this class. We also need  to overload some operators this time around
    as our dicitonary will later use them to compare keys ensuring
    that we don't have repeat keys. 
**********************************************/
template<typename keyType, typename valueType>
class ENTRY{
private:
    keyType key;
    valueType value; 
public:
    ENTRY();
    ENTRY(const keyType& newKey, const valueType& newValue); 
    
    valueType getValue() const;
    keyType getKey() const;
    void setValue(const valueType& newValue);
    void setKey(const keyType& searchKey);
    bool operator==(const ENTRY<keyType, valueType>& rhs) const; 
    bool operator>(const ENTRY<keyType, valueType>& rhs) const;

};

#include "entry.cpp"

#endif //ENTRY_H