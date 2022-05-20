#ifndef GRAPH_H
#define GRAPH_H

#include "igraph.h"
#include <string>
#include <stack>
#include <queue>

//Class Constant 
const int SIZE = 5; 

/**********************************************
    This is the graph class that inherits from our graph interface. It has some 
    extra implementations that weren't in the graph interface as they are unique to this graph
    and helped me reduce redundant code. This graph is implemented by using an adjaceny matrix. This
    was done due to how much we access the graph's weights associated with edges to reduce the time complxity. 
**********************************************/
template<typename T>
class GRAPH: public IGRAPH<T>{
private: 
    int edgeWeightTracker[SIZE][SIZE];
    T vertexArray[SIZE]; 
    int verticies{}; 
    int edges{};
    bool seen[SIZE]; //Used for our search functions to determine which verticies are visited

    std::stack<T> depthFirstSearch; 
    std::queue<T> breadthFirstSearch; 

    //Used to reduce redundant code that looked for where vertex was within the 2D matrix
    bool contains(T vertex); 

public:
    GRAPH(); 
    
    virtual int getNumVertices() const override;
    virtual int getNumEdges() const override;
    virtual bool add(T start, T end, int edgeWeight) override;
    virtual bool remove(T start, T end) override; 
    virtual int getEdgeWeight(T start, T end) const override;
    virtual void depthFirstTraversal(T start, void visit(T&)) override; 
    virtual void breadthFirstTraversal(T start, void visit(T&)) override;
    
    //Added as it was needed to reset our seen array when we call the search function
    //multiple times 
    void resetSeen();

    //Needed for the brute force algo so we could take verticies and store them so we can
    //run permutations 
    T getVertex(int& pos) const; 

    virtual ~GRAPH();
};

#include "graph.cpp"

#endif //GRAPH_H