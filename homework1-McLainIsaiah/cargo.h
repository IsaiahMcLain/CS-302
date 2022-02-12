#ifndef CARGO_H
#define CARGO_H
#include<iostream>
#include<string>

/**********************************************
    This is the cargo class which contains the overloaded operators 
    used in the train class. The cargo class has a weight and type. 
    The cargo class in not templated like it's relative the person class
    becuase I couldn't find a way to make the overloaded + operator work
    with a templated class due to c++'s reliance on type inferencing with 
    templates. 
**********************************************/
class Cargo {
//Outputs formatted cargo objects
friend std::ostream& operator<<(std::ostream& out, const Cargo& obj);

private:
    double weight;
    std::string type;

public:
    Cargo(); 
    Cargo(const double& weight, const std::string& type); 
    
    //Used to add up total weights for train class, unlike person class
    //this overloaded operator is a member not a friend due to need to return
    //this operator
    Cargo& operator+(const Cargo& rhs);
};

#include "cargo.cpp"

#endif //CARGO_H