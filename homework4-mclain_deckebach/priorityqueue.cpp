#include "priorityqueue.h"

template<typename T> 
PRIORITYQUEUE<T>::PRIORITYQUEUE()
    :front{0}, back{DEFAULT_CAPACITY - 1}, size{0}{

}

template<typename T>
bool PRIORITYQUEUE<T>::isEmpty() const{
    return size == 0; 
}

template<typename T>
bool PRIORITYQUEUE<T>::enqueue(const T& newEntry){
    bool canEnqueue = size < DEFAULT_CAPACITY; 
    
    //Since queue is empty, no need to deal with priority
    if (canEnqueue && size == 0){
        back = (back + 1) % DEFAULT_CAPACITY; 
        items[back] = newEntry;
        size++;
    }
    //Priority matters when queue not empty
    else if(canEnqueue){
        int temp = size; //Used so actual size isn't affected
        
        //Loops through and moves each item back by 1 and places 
        //highest priority item in front
        if(items[front] < newEntry){
            int i = back;
            while(temp > 0){
                items[(i + 1) % DEFAULT_CAPACITY] = items[i]; 
                --temp;
                --i;
            }
            items[front] = newEntry;
        }
        //If item being added is lowest priority, just add to back
        else if(items[back] > newEntry){
            items[(back + 1) % DEFAULT_CAPACITY] = newEntry;
        }
        //If newEntry lies somewhere between queue priority wise run through this logic
        else{
            int i = back; //Used so back is not changed
            while(temp > 0){
                //Moves item back by 1 and decrements to check next item
                if(items[i] < newEntry){
                    items[(i + 1) % DEFAULT_CAPACITY] = items[i]; 
                    i--;
                    temp--;
                }
                //Adds items at current queue slot 
                else{
                    items[(i + 1) % DEFAULT_CAPACITY] = newEntry;
                    break; 
                }   
            }
        }
        size++;
        back = (back + 1) % DEFAULT_CAPACITY;
    }   
    return canEnqueue; 
}

template<typename T>
bool PRIORITYQUEUE<T>::dequeue(){
    bool canDequeue = !isEmpty(); 

    if(canDequeue){
        front = (front + 1) % DEFAULT_CAPACITY; 
        size--;
    }

    return canDequeue;
}

template<typename T>
T PRIORITYQUEUE<T>::peekFront() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return items[front];
    }
    else{
        throw std::runtime_error("Attempted to peek an empty queue");
    }
}

template<typename T>
PRIORITYQUEUE<T>::~PRIORITYQUEUE(){
    
}