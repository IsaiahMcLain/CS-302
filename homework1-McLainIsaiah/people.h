#ifndef PEOPLE_H
#define PEOPLE_H
#include<iostream>
#include<string>

/**********************************************
    This is the person class which is used inside the templated bus
    class. A person has a height and name assocaited with them. This
    class overloads the operators needed for the bus class to work. 
**********************************************/
template<typename T1, typename T2>
class People {

//Formatted output for people
template<typename T3, typename T4>
friend std::ostream& operator<<(std::ostream& out, const People<T3,T4>& obj);

//Enables sorting to work, used to compare < values
template<typename T3, typename T4>
friend bool operator<(const T3& lhs, const T4& rhs); 

//Enables sorting to work, ensures heights aren't ==
template<typename T3, typename T4>
friend bool operator==(const T3& lhs, const T4& rhs);

private:
    T1 height;
    T2 name;

public:
    People();
    People(const T1& height, const T2& name);
};

#include "people.cpp"

#endif //PEOPLE_H
