#include "queue.h"

template<typename T>
QUEUE<T>::QUEUE():front{0}, back{DEFAULT_CAPACITY - 1}, size{0} {};

template<typename T>
bool QUEUE<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
bool QUEUE<T>::enqueue(const T& newEntry) {
    bool canEnqueue = size < DEFAULT_CAPACITY - 1;

    //Implementation of a circular array, modulo prevents array from
    //going outside of it's size but allows array to allocate
    //data in a circular fashion
    if (canEnqueue) {
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        size++;
    }

    return canEnqueue;
}

template<typename T>
bool QUEUE<T>::dequeue() {
    bool canDequeue = !isEmpty();

    //Front needs to be used with modulo in order to keep 
    //array circular and from causing seg fault error
    if (canDequeue) {
        front = (front + 1) % DEFAULT_CAPACITY;
        size--;
    }

    return canDequeue;
}

template<typename T>
T QUEUE<T>::peekFront() const {
    bool canPeek = !isEmpty();

    if (canPeek) {
        return items[front];
    }
    else {
        throw std::runtime_error("Attempted to peek at an empty queue.");
    }
} 

template<typename T>
QUEUE<T>::~QUEUE() {};