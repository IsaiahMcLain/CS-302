/**********************************************
    Program for CS302, meant to work with C++ ADT list data structure. 
    This program is a todo list that a user can use to add, remove, complete
    or change items on their todo list. 
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 2/9/2022
**********************************************/
#include <iomanip>
#include <limits>
#include "todolist.h"

//Prototypes
void inputValidation(int userChoice); 
void menu(); 
void programCases(int userChoice);
void displayList(const ToDoList<std::string>& todolist);

//Global Constant 
const int QUIT = 5; 


/**********************************************
    This function is the main driver of the program and contains the main
    looping logic that enables the program to continue running until
    the user decides to quit the program. It takes the user's input
    and transfers it to other functions that need it.
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    bool running = true; 
    
    while(running){ 
        menu(); 
        int userChoice{};
        std::cin >> userChoice;
        inputValidation(userChoice);
        if(userChoice == QUIT){
            running = false;
            break; 
        }
        else{
            programCases(userChoice); 
        }
    } 
    return 0;
}

/**********************************************
    This function just displays the options to the user and prompts for
    input
    @param none
    @return none (void) 
**********************************************/
void menu(){
    std::cout << std::left << std::setw(15) << "TODO LIST" << std::endl; 
    std::cout << std::right << "1. Add Task" << std::endl;
    std::cout << "2. Complete Task" << std::endl; 
    std::cout << "3. Display List" << std::endl; 
    std::cout << "4. Complete All Tasks in List" << std::endl;
    std::cout << "5. Quit Program" << std::endl; 
    std::cout << "Please choose an option listed above:" << std::endl; 
}

/**********************************************
    This function checks user input and makes sure that 
    the that the input is a number not a character. 
    @param int userChoice
    @return none (void)
**********************************************/
void inputValidation(int userChoice) {
	if (!isdigit(userChoice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        //Numeric limits enables no hardset value of characters to be cleared, user could insert
        //infinite amount of chars and the program will still clear the input buffer.
	}
}

/**********************************************
    This function goes through the program logic to determine
    what choice the user made and then calls the method on the
    object depending on the user's choice.
    @param int userChoice
    @return none (void) 
**********************************************/
void programCases(int userChoice){
    bool validate; 
    
    static ToDoList<std::string> todolist; //Made static so that program will keep changes done in if statements
    std::string todoItem{}; 
    int itemPos{}; 
    
    if(userChoice == 1){
        std::cout << "Please enter the item number FIRST then TODO item to the list" << std::endl; 
        std::cin >> itemPos; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, todoItem);
        validate = todolist.insert(itemPos, todoItem); 
        if(!validate){
            std::cout << "Item wasn't added to list, please make sure the list number" << 
            " you enter is only 1 higher than current list size or within the current size of the list" 
            << std::endl;
        }
    }
    if(userChoice == 2){
        std::cout << "Please enter the number on the list that you would like to complete" << std::endl;
        std::cin >> itemPos;
        validate = todolist.remove(itemPos);
        if(!validate){
            std::cout << "Item wasn't completed, please make sure the number you entered exists on the list." << std::endl; 
        }
    }
    if(userChoice == 3){
            displayList(todolist);  
    }
    if(userChoice == 4){
        todolist.clear(); 
        std::cout << "Congrats! You have completed your to do list." << std::endl; 
    }
    else{
        std::cout << "Please enter a correct choice from the menu" << std::endl; 
    }
}

/**********************************************
    This function goes through a for loop and displays todo list
    to user. 
    @param const ToDoList<std::string>& todolist
    @return none (void) 
**********************************************/
void displayList(const ToDoList<std::string>& todolist){
    std::cout << "Displaying list: " << std::endl; 
    for(int i = 1; i <= todolist.getLength(); i++){
        std::cout << i << ". " << todolist.getEntry(i) << std::endl; 
    }
}
