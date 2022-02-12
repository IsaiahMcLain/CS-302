/**********************************************
    Program for CS302, meant to work with C++ advanced OOP topics such as templates,
    interfaces, inheritance, ad hoc polymorphism, etc. Through use of diffrent classes
    called trains and buses which hold cargo and people. 
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 1/30/2022
**********************************************/
#include "bus.h"
#include "train.h"
#include "people.h"
#include "cargo.h"


/**********************************************
    This function is the main driver of the program, it handles all the 
    test cases for this program. 
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    std::list<People<int, std::string>> passengers;
    Bus<People<int, std::string>> bus(passengers);
    People<int, std::string> person(1, "Isaiah"); 
    People<int, std::string> person1(7, "John");
    People<int, std::string> person2(5, "James");
    
    bus.load(person);
    bus.load(person1);
    bus.load(person2); 
    bus.report(); 
    int cost = 5; 
    bus.fare(cost); 
    
    std::cout << std::endl; 
    std::cout << "Sorting" << std::endl;
    bus.sort();
    bus.report();
    
    std::cout << std::endl;
    bus.move();
    bus.unLoad();
    bus.report();

    std::cout << std::endl; 
    bus.move();
    bus.empty();
    bus.report();
    cost = 2;
    bus.fare(cost);
    std::cout << std::endl; 

    std::list<Cargo> cargo;
    Train<Cargo> train(cargo);
    Cargo cargo1(1.1, "Food"); 
    Cargo cargo2(7.4, "Wood");
    Cargo cargo3(88, "Fridge");

    train.load(cargo1);
    train.load(cargo2);
    train.load(cargo3);
    train.report();
    train.add();
    
    std::cout << std::endl; 
    train.move();
    train.unLoad(); 
    train.report();
    train.add();
    std::cout << std::endl; 

    train.move();
    train.empty();
    train.report();


    return 0;
}
