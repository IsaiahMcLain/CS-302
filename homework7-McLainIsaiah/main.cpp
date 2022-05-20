/**********************************************
    Program for CS302 that implements a graph data structure to solve the
    travelling salesman problem through the naive or brute force method. (Wasn't able
    to complete the entire problem as I ran into issues with my algo). Will come back
    and finish
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 4/24/2022
**********************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "graph.h"

//Prototypes
template<typename T>
void display(T& vertex); 
template<typename T>
void createGraph(GRAPH<T>& graph, std::ifstream& inFile);
int bruteForceAlgo(GRAPH<std::string>& graph, std::string startPos); 


/**********************************************
    This function is the main driver of the program, it handles
    the loading of the file into the program as well as the function calls
    that operate on the graph data structure which is instantiated from the 
    input file. 
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    GRAPH<std::string> graph; 
    std::ifstream inFile("cities.txt"); 
    
    if(inFile){
        createGraph(graph, inFile);
    }
    else{
        std::cerr << "Could not open file" << std::endl; 
        return 1;
    }

    inFile.close(); 

    int startPos{0};
    std::string startVertex = graph.getVertex(startPos);

    int shortestPath = bruteForceAlgo(graph, startVertex);

    std::cout << "Shortest path: " << shortestPath << std::endl;  
    
    return 0; 
}


/**********************************************
    This function is used to display output to the console, is also
    known as the visit function within the graph data structure. 
    @param T& vertex
    @return none (void)
**********************************************/
template<typename T>
void display(T& vertex){
    std::cout << "Vertex: " << vertex << std::endl; 
}

/**********************************************
    This function is used to load the verticies and their distances
    into the graph from the input file. 
    @param GRAPH<T>& graph, std::ifstream& inFile
    @return none (void)
**********************************************/
template<typename T>
void createGraph(GRAPH<T>& graph, std::ifstream& inFile){
    T vertex1;
    T vertex2;
    int distance; 
    int i{0};

    while(!inFile.eof() && i < SIZE){
        inFile >> vertex1 >> vertex2 >> distance;
        graph.add(vertex1, vertex2, distance);
        i++;
    }
}

/**********************************************
    This function is the implementation of the brute force method to solve the TSP
    problem. The function currently has issues which I believe are either due to
    scope resolution errors or improper accessing of the graph. This function is supposed
    to take all the verticies and calculate every path they can take from each vertex
    and then add up the values to get the min path. 
    @param T& vertex
    @return int minPathDis, minimum distance path that salesperson can take 
**********************************************/
int bruteForceAlgo(GRAPH<std::string>& graph, std::string startPos){
    std::vector<std::string> verticies; 

    //Loads vertex's into vector that we can use permutaion function on to ensure
    //We've used every possible path, omit start position as we are starting from
    //there in our next logic
    for(int i = 0; i < SIZE; i++){
        if(graph.getVertex(i) != startPos){
            verticies.push_back(graph.getVertex(i));
        } 
    } 

    // for(int i = 0; i < verticies.size(); i++){
    //     std::cout << verticies.at(i) << std::endl; 
    // }

    static int minPathDis{20000000};  //Needs to be a high value that obvously can't be a distance for our std::min

    //Do while loop to go through every permutation 
    do{
        int currentPathDis{0};

        std::string startPosTemp = startPos; //Need temp as we will change what the startpos is

        //Goes through every path at the vertex and adds it to current path (what isn't working correctly)
        for(int i = 0; i < verticies.size(); i++){
            currentPathDis += graph.getEdgeWeight(startPosTemp, graph.getVertex(i));
            startPosTemp = verticies.at(i);
        } 

        //Need to do final addition of starting vertex distance to the path distance
        currentPathDis += graph.getEdgeWeight(startPosTemp, startPos);

        //Calculate and save min path distance
        minPathDis = std::min(minPathDis, currentPathDis);

    }while(std::next_permutation(verticies.begin(), verticies.end())); //Works by returning bool value which tells us when every vertex in our vector has been accessed

    return minPathDis; 
}

    
