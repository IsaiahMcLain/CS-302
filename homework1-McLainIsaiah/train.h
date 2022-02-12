#ifndef TRAIN_H
#define TRAIN_H
#include "itransporter.h"

/**********************************************
    this is the train class which inherits from ITransporter, it
    contains a list of cargo that are onboard and can add up the
    total weight of the cargo and tell the user.
**********************************************/
template<typename T>
class Train: public ITransporter<T> {
private:
    std::list<T> cargo; 

public:
    Train();
    Train(std::list<T> cargo);

    //Adds total weight of all cargo 
    void add();

    virtual void load(T& obj) override;
    virtual void unLoad() override;
    virtual void empty() override;
    virtual void move() override;
    virtual void report() override;
};

#include "train.cpp"

#endif //TRAIN_H
