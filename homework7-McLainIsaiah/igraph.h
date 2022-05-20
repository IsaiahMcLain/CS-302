#ifndef IGRAPH_H
#define IGRAPH_H

/**********************************************
    This is the graph interface which contains all the functions
    as determined in class that are needed for a undirected, connected graph. 
**********************************************/
template<typename T>
class IGRAPH{
public: 
    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;
    virtual bool add(T start, T end, int edgeWeight) = 0;
    virtual bool remove(T start, T end) = 0; 
    virtual int getEdgeWeight(T start, T end) const = 0;
    virtual void depthFirstTraversal(T start, void visit(T&)) = 0; 
    virtual void breadthFirstTraversal(T start, void visit(T&)) = 0;

    virtual ~IGRAPH() { }

};

#endif //IGRAPH_H