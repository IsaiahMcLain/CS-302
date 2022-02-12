#ifndef BUS_H
#define BUS_H
#include "itransporter.h"

/**********************************************
    This is the bus class which inherits from ITransporter, it
    contains a list of passengers that are onboard and can sort them
    by height. 
**********************************************/
template<typename T>
class Bus: public ITransporter<T> {
private:
    std::list<T> passengers;

public:
    Bus();
    Bus(std::list<T> passengers);

    //Sorts passengers by height 
    void sort();
    //Calculates fare for all passengers based off fare price inputed
    void fare(int price);

    virtual void load(T& obj) override;
    virtual void unLoad() override;
    virtual void empty() override;
    virtual void move() override;
    virtual void report() override;

};

#include "bus.cpp"

#endif //BUS_H
