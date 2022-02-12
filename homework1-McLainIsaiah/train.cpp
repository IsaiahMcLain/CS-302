#include "train.h"

template<typename T>
Train<T>::Train(){
}

template<typename T>
Train<T>::Train(std::list<T> Ncargo){
    cargo = Ncargo;
}

template<typename T>
void Train<T>::load(T& obj){
    cargo.emplace_front(obj);
}

template<typename T>
void Train<T>::unLoad(){
    cargo.pop_back();
}

template<typename T>
void Train<T>::empty(){
    cargo.clear();
}

template<typename T>
void Train<T>::move(){
    std::cout << "The Train has reached it's next destination" << std::endl;
}

template<typename T>
void Train<T>::report(){
    if(cargo.size() != 0){
        std::cout << "The train is currently not empty and has: "
        << cargo.size() << " peices of cargo on board at this time."
        << std::endl;
        for(auto& i: cargo){
            std::cout << "Cargo: " << i << std::endl;
        }
    }
    else{
        std::cout << "The train is currently empty." << std::endl;
    }
}

/**********************************************
    This function uses a range-based for loop to go through list
    and add up all the weights of the cargo objects inside. It uses 
    the overloaded + operator within the cargo class to do this. 
    @param none
    @return none
**********************************************/
template<typename T> 
void Train<T>::add(){
    T tWeight; 
    for(auto& i: cargo){
        tWeight = tWeight + i; 
    }
    std::cout << "Total Weight of Cargo: " << tWeight << " lbs" << std::endl; 
}


