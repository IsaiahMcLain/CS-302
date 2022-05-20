#ifndef ITREE_H
#define ITREE_H


/**********************************************
    This is the tree interface which contains all the functions
    as determined in class that are needed for a binary search tree. 
**********************************************/
template<typename T>
class ITree {
public: 
    virtual bool isEmpty() const = 0; 
    virtual int getHeight() const = 0; 
    virtual int getNumberOfNodes() const = 0;
    virtual T getRootData() const = 0;
    virtual bool add(const T& newEntry) = 0; 
    virtual bool remove(const T& anEntry) = 0;
    virtual void clear() = 0; 
    virtual bool contains(const T& anEntry) const = 0;
    virtual ~ITree() { }
};


#endif //ITREE_H