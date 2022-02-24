/**********************************************
    Program for CS302, meant to work with C++ ADT stack data structure. 
    This program is a infix notation to postfix notation converter and solver 
    that allows a user to enter typical standard math notation equations 
    and is then converted and solved in postfix notation. 
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 2/18/2022
**********************************************/
#include "stack.h"

//Prototypes 
std::string toPostFixEq(std::string inFixEq);
int precedence(std::string temp);
int postFixCalulator(std::string postFixEq);

/**********************************************
    This function is the main driver of the program and takes the main user input
    and delivers the input to the proper functions. This function then
    outputs the results to the user. 
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    std::string inFixEq;
    std::cout << "Please enter a mathematical expression. The expression "
    << "can only contain single digit numbers and the operations () +-/*%" << std::endl;
    std::getline(std::cin, inFixEq); 

    std::string postFixEq = toPostFixEq(inFixEq);
    std::cout << "PostFix Equation: " << postFixEq << std::endl;
    
    int returnValue{};
    returnValue = postFixCalulator(postFixEq); 
    std::cout << "Answer to Equation: " << returnValue << std::endl; 
    
    return 0; 
}

/**********************************************
    This function is the main logic tree that converts the user's inputed infix
    notation to postfix notation. 
    @param std::string inFixEq
    @return std::string postFixEq
**********************************************/
std::string toPostFixEq(std::string inFixEq){
    std::string temp{};
    static std::string postFixEq;
    Stack<std::string> operatorStack;   
    
    //For loop runs through size of equation to convert
    for(int i = 0; i < inFixEq.size(); i++){
        temp = inFixEq.at(i); 
        if(temp == "("){
            operatorStack.push(temp);
        }
        else if(temp == "*" || temp == "/" || temp == "%"){
            if(operatorStack.isEmpty())
                operatorStack.push(temp);
            else{
                if(operatorStack.peek() == temp){
                    postFixEq += temp; 
                }
                else{
                    operatorStack.push(temp);
                }
            } 
        }
        else if(temp == "+" || temp == "-"){
           //Must check this condition first as if stack is empty it will cause seg fault error if this statment doesn't occur
           if(operatorStack.isEmpty()) 
                operatorStack.push(temp); 

            //If precedence of */% ran into which is higher, or and additional +- 
            //The stack is emptied and all operators are put into string except for +-
            //that was the most recent operator
            else if(precedence(operatorStack.peek()) >= 1){
                while(!operatorStack.isEmpty()){
                    postFixEq += operatorStack.peek();
                    operatorStack.pop();
                }
                operatorStack.push(temp);
            } 
            else{
                operatorStack.push(temp); //Needed to actually push on +
            }
        }
        //If closed ) run into, stack is fully emptied of it's operators until ( is run into
        else if(temp == ")"){
          while(!operatorStack.isEmpty()){
              if(operatorStack.peek() == "("){
                  operatorStack.pop();
              }
              else{
                postFixEq += operatorStack.peek(); 
                operatorStack.pop();
              }
          }  
        }
        //Just adds value to string if it's any single digit #
        else if(temp >= "0" && temp <= "9"){
            postFixEq += temp; 
        }
    }
    //Needed outside of for loop as stack will sometimes still contain operators
    //that are meant to be applied to all the values. 
    while(!operatorStack.isEmpty()){
                postFixEq += operatorStack.peek();
                operatorStack.pop();
            }
    return postFixEq; 
}

/**********************************************
    This function gives an integer value precedence to the
    operators so that the program can acutally tell what precendence 
    is greater than the other since it's not inbuilt in c++
    @param std::string temp
    @return int precedence
**********************************************/
int precedence(std::string temp){
    if(temp == "*" || temp == "/" || temp == "%"){
        return 2; 
    }
    else if(temp == "+" || temp == "-"){
        return 1; 
    }
    return 0;
}

/**********************************************
    This function goes through the logic of conducting operations
    on the number values from the postfix equation and returns the result
    @param std::string posFixEq
    @return int operandStack.peek() (final value)
**********************************************/
int postFixCalulator(std::string postFixEq){
    std::string temp{};
    Stack<int> operandStack;  

    //Runs through size of equation 
    for(int i = 0; i < postFixEq.size(); i++){
        temp = postFixEq.at(i); 
        //Convert and add value to stack if it's any single digit #
        if(temp >= "0" && temp <= "9"){
            int tempNumber{};

            tempNumber = stoi(temp); //Converts string to int
            operandStack.push(tempNumber); 
        }
        else{
            int operand1{};
            int operand2{}; 
                
            operand1 = operandStack.peek();
            operandStack.pop();
            operand2 = operandStack.peek();
            operandStack.pop(); 

            //Logic tree that determines which operation to conduct on the two operands
            if(temp == "*")
                operandStack.push(operand1 * operand2); 
            else if(temp == "/")
                operandStack.push(operand2 / operand1); 
            else if(temp == "%")
                    operandStack.push(operand2 % operand1);
            else if(temp == "+")
                operandStack.push(operand1 + operand2); 
            else if(temp == "-")
                    operandStack.push(operand2 - operand1);   
                 
        }
    }
    return operandStack.peek(); //returns final result
}
     
