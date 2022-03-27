#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>

/**********************************************
    This is the Event class which is used in tandem with the queue and priority
    queue to store attributes every customer will have. 
    It contains the time, type, and duration of the customer,
    it also overloads the < > <= operators so that the priority queue can work. 
**********************************************/
class EVENT{
    //Enables display of time
    friend std::ostream &operator<<(std::ostream &out, const EVENT &obj); 
private: 
    char type; //A for arrival D for departure
    int time;
    int duration;
public: 
    EVENT();
    EVENT(char type, int time); 
    EVENT(char type, int time, int duration); 

    char getType() const; 
    int getTime() const;
    int getDuration() const; 

    void setType(char nType);
    void setTime(int nTime);
    void setDuration(int nDuration); 

    //What these return is opposite of what is expected as
    //time works diffrently than from comparing normal ints
    //lesser time will "greater" than a higher time
    bool operator<(const EVENT &rhs) const;
    bool operator<=(const EVENT &rhs) const;
    bool operator>(const EVENT &rhs) const;

};

#endif //EVENT_H