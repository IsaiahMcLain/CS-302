#ifndef ITRANSPORTER_H
#define ITRANSPORTER_H
#include<iostream>
#include<list>

/**********************************************
    This is the main interface of the program and contains the
    function behaviors used in both the train and bus classes. 
**********************************************/
template<typename T>
class ITransporter {
public:
    //Behaviors 
    //Loads object into list
    virtual void load(T& obj) = 0;
    
    //Unloads object from list
    virtual void unLoad() = 0;
    
    //Completely empties list
    virtual void empty() = 0;
    
    //"moves" transporter
    virtual void move() = 0;
    
    //Gives details about transporter and it's contents
    virtual void report() = 0;
};

#endif //ITRANSPORTER_H
