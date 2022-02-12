template<typename T>
Bus<T>::Bus(){

}

template<typename T>
Bus<T>::Bus(std::list<T> Npassengers){
    passengers = Npassengers;
}

template<typename T>
void Bus<T>::load(T& obj){
    passengers.emplace_front(obj);
}

template<typename T>
void Bus<T>::unLoad(){
    passengers.pop_back();
}

template<typename T>
void Bus<T>::empty(){
    passengers.clear();
}

template<typename T>
void Bus<T>::move(){
    std::cout << "The Bus has reached it's next stop" << std::endl;
}

template<typename T>
void Bus<T>::report(){
    if(passengers.size() != 0){
        std::cout << "The bus is currently not empty and has: "
        << passengers.size() << " passengers on board at this time."
        << std::endl;
        for(auto& i: passengers){
            std::cout << "Passenger order: " << i << std::endl;
        }
    }
    else{
        std::cout << "The bus is currently empty." << std::endl;
    }
}

/**********************************************
    This function uses a range-based for loop to go through list
    and it assigns type T(person in this case) to a temp variable,
    if the front of list is smaller than the iterated next object. If
    it is then the object is removed from the list (bigger one) and placed
    in the front of the list. It uses the overloaded < operator from
    the person class to execute this. 
    @param none
    @return none
**********************************************/
template<typename T>
void Bus<T>::sort(){
    for(auto& i : passengers){
        if(passengers.front() < i){
            T temp = i; 
            passengers.remove(i); 
            passengers.emplace_front(i);
        }
    }
}

/**********************************************
    This function takes inputed fare price and multiplies it across
    the size of the list (i.e amount of passengers) and stores that 
    in a total to give the total fare price of the bus. 
    @param int price
    @return none
**********************************************/
template<typename T>
void Bus<T>::fare(int price){
    std::cout << "Current fare is: " << price << "$ " << std::endl; 
    if(passengers.size() != 0){
        int total = passengers.size() * price;
        std::cout << "Total fare for all passengers is: " << total << "$" << std::endl;
    }
    else{
        std::cout << "No fare total as there is no passengers" << std::endl; 
    }
}


