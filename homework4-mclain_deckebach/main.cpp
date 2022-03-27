/**********************************************
    Program for CS302, meant to work with C++ ADT queue and priority queue data 
    structure. This program represents a bank simulation in which 
    customers come into the bank at different times to be helped by a bank
    teller. The program keeps track of the customers in line and figures
    out when they arrive and depart to calculate an average wait time. 
    @file main.cpp 
    @author Isaiah McLain & Michael Dekebach
    @version 1.0 2/28/2022
**********************************************/
#include <fstream>
#include <sstream>

#include "priorityqueue.h"
#include "queue.h"
#include "event.h"

//Prototypes
void loadData(std::string& fileName, PRIORITYQUEUE<EVENT>& eventsPQ);
EVENT stringToArrivalEvent(std::string line);
void processArrival(int& tellerAvailable, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ);
void processDeparture(int& tellerAvailable, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ);

/**********************************************
    Main driver. Imports a text file of arrivals, and simulates the line
    at a bank. Prints to the console the times of each arrival and departure,
    before finally outputing the average wait time for each customer.
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){

    PRIORITYQUEUE<EVENT> eventsPQ;
    QUEUE<EVENT> bankQ;
    int availableTellers = 0;
    int totalCustomers = 0;
    int totalWaitTime = 0;
    int maxWait = 0;
    std::string fp = "data.txt";

    // Reads text file of events into a priority queue
    loadData(fp, eventsPQ);

    // Get the number of tellers from the user
    while (availableTellers < 1) {
        std::cout << "Enter the number of tellers to simulate: ";
        std::cin >> availableTellers;
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }

    // Process event-drive simulation
    std::cout << std::endl << "Simulation Begins" << std::endl;
    while (!eventsPQ.isEmpty()) {

        EVENT newEvent = eventsPQ.peekFront();

        // Arbitrarily process arrival events first
        if (newEvent.getType() == 'A') {
            
            totalCustomers++;
            processArrival(availableTellers, eventsPQ, bankQ);
            std::cout << "Processing an arrival event at time:  " << std::right << newEvent.getTime() << std::endl;
        }
        else if (newEvent.getType() == 'D') {

            // If someone departs from teller and there is a bank queue,
            // then calculate the wait time of the 1st customer in line
            // 1st-in-line's wait time = current time - arrival time
            if (!bankQ.isEmpty()) {

                int nextInLinesArrival = bankQ.peekFront().getTime();
                int currentTime = newEvent.getTime();
                int waitTime = currentTime - nextInLinesArrival;
                totalWaitTime += waitTime;

                if (waitTime > maxWait) {
                    maxWait = waitTime;
                }
            }

            processDeparture(availableTellers, eventsPQ, bankQ);
            std::cout << "Processing a departure event at time: " << std::right << newEvent.getTime() << std::endl;
        }
        // Fail safe in case of unexpected EVENT type
        else {
            throw std::runtime_error("Unexpected EVENT type encountered. Exiting");
        }
    }

    // Calculate and display the results
    float avgWait = ((float)totalWaitTime) / totalCustomers;
    std::cout << "Simulation Ends" << std::endl << std::endl;
    std::cout << "Final Statistics:" << std::endl;
    std::cout << "  Total number of people processed: " << totalCustomers << std::endl;
    std::cout << "  Average amount of time spent waiting: " << avgWait << std::endl;
    std::cout << "  Maximum amount of time spent waiting: " << maxWait << std::endl;

    return 0; 
}

/**********************************************
    Processes a departure event, removing the event from the priority queue
    and moving the next customer to the teller by calculating their departure
    event, if applicable.
    @param bool& tellerAvailable, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ
    @return nothing (void)
**********************************************/
void processDeparture(int& availableTellers, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ) {
    
    // Current time is needed to calc departure time for next up in the bank queue
    int now = eventsPQ.peekFront().getTime();
    eventsPQ.dequeue();

    // As the person with the teller departs, move first in line to the teller
    if (!bankQ.isEmpty()) {
        
        // Departure time is calculated when the first person in line
        // moves up to start with the teller, as departure = now + duration
        int departureTime = now + bankQ.peekFront().getDuration();
        eventsPQ.enqueue(EVENT('D', departureTime));
        bankQ.dequeue();
    }
    else {
        availableTellers++;
    }
}

/**********************************************
    Processes an arrival event, removing the event from the priority queue
    and moving the customer into the bank queue or to the teller, depending
    on whether the teller is available.
    @param bool& tellerAvailable, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ
    @return nothing (void)
**********************************************/
void processArrival(int& availableTellers, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ) {
    
    EVENT arrival = eventsPQ.peekFront();
    eventsPQ.dequeue();

    // If there's no bank line, move the customer directly to the teller
    if (bankQ.isEmpty() && (availableTellers > 0)) {
        int departureTime = arrival.getTime() + arrival.getDuration();
        eventsPQ.enqueue(EVENT('D', departureTime));
        availableTellers--;
    }
    else {
        bankQ.enqueue(arrival);
    }
}

/**********************************************
    Reads in a text file of arrival times and durations constructing an EVENT
    instance for each and adding it to the priority queue
    @param std::string& fileName, PRIORITYQUEUE<EVENT>& eventsPQ, QUEUE<EVENT>& bankQ
    @return nothing (void)
**********************************************/
void loadData(std::string& fileName, PRIORITYQUEUE<EVENT>& eventsPQ) {
    
    std::ifstream input(fileName);
    std::string line;

    if (input.is_open()) {

        while(std::getline(input, line)) {
            EVENT newEvent = stringToArrivalEvent(line);
            eventsPQ.enqueue(newEvent);
        }
        input.close();
    }
    else {
        throw std::runtime_error("Could not open file");
    }
}

/**********************************************
    Takes a string as '[time] [duration]' and returns an arrival
    EVENT with the appropriate time and duration attributes
    @param std::string line
    @return EVENT 
**********************************************/
EVENT stringToArrivalEvent(std::string line) {
    
    int time;
    int duration;
    std::istringstream iss(line);

    if (iss >> time >> duration) {
        return EVENT('A', time, duration);
    }
    else {
        throw std::runtime_error("Cannot convert string to Event. Format must be 'T D'");
    }

}