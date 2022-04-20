/**********************************************
    Program for CS302, This program is meant to implement a binary search tree and
    output the data stored within the tree by using three different 
    tree traversal techniques. Note: Common practice to have binary tree inherit interface
    then have the BST inherit from the binary tree, this was not done for sake
    of complexity to be simple. 
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 4/18/2022
**********************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "linkedbtree.h"

//Global Constant 
const int TREE_SIZE = 100; 
const int TREE_RANGE = 200; 
std::string FILE_NAME; 

//Prototypes
void makeTree(LinkedBTree<int>& BST); 
void display(int& num); 
void writeToFile(int& num);


/**********************************************
    This function is the main driver of the program, it initilizes 
    the binary search tree and calls functions onto the tree. 
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    LinkedBTree<int> BST;
    makeTree(BST); //Initlizes tree with values
    
    std::cout << "Inorder Traversal" << std::endl; 
    BST.inorderTraverse(display); //How to pass a function as a parameter
    std::cout << std::endl << std::endl;
    std::cout << "Preorder Traversal" << std::endl; 
    BST.preorderTraverse(display);
    std::cout << std::endl << std::endl;
    std::cout << "Postorder Traversal" << std::endl; 
    BST.postorderTraverse(display);

    FILE_NAME = "inorder.txt"; //File_name is a global value so it isn't passed to function
    BST.inorderTraverse(writeToFile);
    FILE_NAME = "preorder.txt";
    BST.preorderTraverse(writeToFile);
    FILE_NAME = "postorder.txt";
    BST.postorderTraverse(writeToFile);

    return 0;
}

/**********************************************
    This function initlizes random values from a range of 1-200
    into the binary tree. 
    @param LinkedBTree<int>& BST
    @return none (void)
**********************************************/
void makeTree(LinkedBTree<int>& BST){
    srand((unsigned) time(0)); //Seed random values 
    int randNum{}; //Needed to store random value

    for(size_t i = 0; i < TREE_SIZE; i++){
        randNum = rand() % TREE_RANGE; 
        BST.add(randNum);
    }
}

/**********************************************
    This function is used to display all the contents of the binary
    tree, it is called the visit function with the BST header and cpp file. 
    @param int& num
    @return none (void)
**********************************************/
void display(int& num){
    std::cout << num << std::endl; 
}

/**********************************************
    This function opens a file that is passed in from main 
    and then writes the tree's output order to that file.
    @param int& num
    @return none (void)
**********************************************/
void writeToFile(int& num){
    std::ofstream outputFile;
    outputFile.open(FILE_NAME, std::ofstream::app);

    outputFile << num << std::endl; 
    outputFile.close(); 

}