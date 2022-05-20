#ifndef IDICTIONARY_H
#define IDICTIONARY_H

/**********************************************
    This is the dictionary interface which contains all the functions
    as determined in class that are needed for a dictionary. 
**********************************************/
template<typename keyType, typename valueType>
class IDICTIONARY{
public:
    virtual bool isEmpty() const = 0;
    virtual bool add(const keyType& newKey, const valueType& newValue) = 0;
    virtual bool remove(const keyType& targetKey) = 0;
    virtual void clear() = 0;
    virtual bool contains(const keyType& targetKey) const = 0;
    virtual valueType getValue(const keyType& targetKey) const = 0;
    virtual ~IDICTIONARY() { }
};


#endif //IDICTIONARY_H