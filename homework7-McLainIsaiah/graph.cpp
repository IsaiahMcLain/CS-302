#include "graph.h"

template<typename T>
GRAPH<T>::GRAPH()
    :edgeWeightTracker{0}, verticies{-1}, edges{-1}, seen{0}{

}

template<typename T> 
int GRAPH<T>::getNumVertices() const{
    if(verticies == -1){
        return 0; 
    }
    else
        return verticies + 1;  //Need plus 1 due to value being -1 initilized 
}

template<typename T> 
int GRAPH<T>::getNumEdges() const{
   if(edges == -1){
       return 0;
   } 
   else
    return edges + 1; 
}

template<typename T> 
int GRAPH<T>::getEdgeWeight(T start, T end) const{
    int edgeWeight; 
    int startPos;
    int endPos; 

    if(getNumEdges() == 0){
        return 0; 
    }
    else{
        for(int i = 0; i < SIZE; i++){
            if(vertexArray[i] == start){
                startPos = i; 
            }
        }
        for(int i = 0; i < SIZE; i++){
            if(vertexArray[i] == end){
                endPos = i; 
            }
        }

        edgeWeight = edgeWeightTracker[startPos][endPos];
    }
    return edgeWeight; 
}

template<typename T>
bool GRAPH<T>::contains(T vertex){
    for(int i = 0; i < SIZE; i++){
        if(vertexArray[i] == vertex){
            return true; 
        }
    }
    return false; 
}

/**********************************************
    This function is used to add new vertex's to the graph. It runs through
    each possible case that may be run into when adding verticies.
    @param T start, T end, int edgeWeight
    @return bool, tells if add was successful or not
**********************************************/
template<typename T>
bool GRAPH<T>::add(T start, T end, int edgeWeight){
    bool canAdd = (verticies != SIZE - 1) && (edges != SIZE - 1);

    //Used to let us know if the graph already has these verticies or not
    bool containsStart = contains(start);
    bool containsEnd = contains(end); 
    int vertexArrayPos{}; 

    int startPos{};
    int endPos{};

    //Case where graph has the end vertex but not the start
    if(canAdd && (!containsStart) && containsEnd){
        verticies++;
        vertexArray[verticies] = start; 
        
        for(int i = 0; i < SIZE; i++){
            if(vertexArray[i] == end){
                vertexArrayPos = i;
            }
        }

        //Double assignment needed as a 2D matrix can be accessed from two different points
        //that tell the same thing so we need to make sure the weight is the same
        edgeWeightTracker[vertexArrayPos][verticies] = edgeWeight;
        edgeWeightTracker[verticies][vertexArrayPos] = edgeWeight;
        edges++;
    }
    //If graph doesn't have end vertex but has start vertex
    else if(canAdd && (!containsEnd) && containsStart){
        verticies++;
        vertexArray[verticies] = end; 

        for(int i = 0; i < SIZE; i++){
            if(vertexArray[i] == start){
                vertexArrayPos = i;
            }
        }

        edgeWeightTracker[vertexArrayPos][verticies] = edgeWeight;
        edgeWeightTracker[verticies][vertexArrayPos] = edgeWeight;
        edges++;
    }
    //If graph doesn't have either vertex we need to add both
    else if(canAdd && verticies != SIZE - 2 && (!containsEnd) && (!containsStart)){
        verticies++;
        vertexArray[verticies] = start;
        verticies++;
        vertexArray[verticies] = end;

        edgeWeightTracker[verticies - 1][verticies] = edgeWeight;
        edgeWeightTracker[verticies][verticies - 1] = edgeWeight;
        edges++;   
    }
    //If the graph already has both verticies but they aren't connected then we want to
    //connect them and give their edge a weight
    else if(getEdgeWeight(start, end) == 0 && canAdd){
        for(int i = 0; i < SIZE; i++){
            if(vertexArray[i] == start){
                startPos = i; 
            }
            else if(vertexArray[i] == end){
                endPos = i;
            }
        }
        edgeWeightTracker[startPos][endPos] = edgeWeight;
        edgeWeightTracker[endPos][startPos] = edgeWeight;
        edges++;
    }
    
    return true;   
}

/**********************************************
    This function is used to remove an edge from the graph, it also needs to test
    and make sure the vertex still has connections to other points in the graph. Otherwise
    it must remove the vertex as well. 
    @param T start, T end 
    @return bool, tells if remove was successful or not
**********************************************/
template<typename T>
bool GRAPH<T>::remove(T start, T end){
    bool canRemove = true; 
    
    //If graph is empty can't remove
    if(getNumVertices() == 0){
        canRemove = false; 
        return canRemove;
    }

    //Ensure that both verticies are within the graph 
    bool containsStart = contains(start);
    bool containsEnd = contains(end); 

    int vertexArrayPosStart{};
    int vertexArrayPosEnd{};
    int amountOfEdgesStart{}; 
    int amountOfEdgesEnd{};

    //If neither vertex is in the graph, we can't remove anything
    if(canRemove && (!containsStart) || (!containsEnd)){
        canRemove = false;
        return canRemove; 
    }
    //Logic chain for when we have both verticies and graph isn't empty
    else if(containsStart && containsEnd && canRemove){
        //If we have both verticies but their is no edge between them, can't remove edge
        //so we do nothing 
        if(getEdgeWeight(start, end) == 0){
            canRemove = false; 
            return canRemove; 
        }
        //Remove edge and then test each vertex for connectivity to graph
        else{ 
            for(int i = 0; i < SIZE; i++){
                if(vertexArray[i] == start){
                    vertexArrayPosStart = i;
                }
                else if(vertexArray[i] == end){
                    vertexArrayPosEnd = i;
                }
            }
            edgeWeightTracker[vertexArrayPosStart][vertexArrayPosEnd] = 0;
            edgeWeightTracker[vertexArrayPosEnd][vertexArrayPosStart] = 0;
            edges--;

            //For loops test each vertex to see if they have any other edges or not
            for(int i = 0; i < SIZE; i++){
                if(edgeWeightTracker[vertexArrayPosStart][i] != 0){
                    amountOfEdgesStart++;
                }
            }
            for(int i = 0; i < SIZE; i++){
                if(edgeWeightTracker[vertexArrayPosEnd][i] != 0){
                    amountOfEdgesEnd++;
                }
            }

            //If either vertex doesn't have any other connections, we remove the
            //vertex. Due to using an array we "remove" aka ignore it's existance until
            //it's overwritten 
            if(amountOfEdgesStart == 0){
                verticies--;
            }
            if(amountOfEdgesEnd == 0){
                verticies--;
            }
        }
    }
    return canRemove; 
}

/**********************************************
    This function is the depthFirstTraversal and was implmented in an iterative and
    recursive fashion as it was easier for this type of traversal to use some recursion. 
    @param T start, void visit(T&)
    @return void (none)
**********************************************/
template<typename T>
void GRAPH<T>::depthFirstTraversal(T start, void visit(T&)){
    depthFirstSearch.push(start); //Add the start vertex to our stack
    int vertexPos{};
    
    visit(depthFirstSearch.top()); //Display start vertex

    //Get vertex pos from our vertex array and break from loop once found to reduce 
    //time usage
    for(int i = 0; i < SIZE; i++){
        if(vertexArray[i] == start){
            vertexPos = i;
            break;
        }
    }

    //Set our start pos to being seen 
    seen[vertexPos] = true; 

    //Recursivly call the function within the for loop to visit every vertex in our graph
    //through the depthfirst method, this will cause more verticies to be pushed onto stack
    //until all are seen and displayed. Function then springs back as base case reached. (All are seen)
    //Tests to make sure there is an edge between the verticies as well.
    for(int i = 0; i < SIZE; i++){
        if(edgeWeightTracker[vertexPos][i] != 0 && (!seen[i])){
            start = vertexArray[i];
            depthFirstTraversal(start, visit); 
        }
    }

}

/**********************************************
    This function is the breadthFirstTraversal and was implmented in an iterative fashion
    as I had a hard time thinking of how to solve this type of search recursively.
    @param T start, void visit(T&)
    @return void (none)
**********************************************/
template<typename T>
void GRAPH<T>::breadthFirstTraversal(T start, void visit(T&)){
    breadthFirstSearch.emplace(start); //Put our start vertex in the queue
    int vertexPos{};

    //Find where start vertex is within our vertex array
    for(int i = 0; i < SIZE; i++){
        if(vertexArray[i] == start){
            vertexPos = i;
            break;
        }
    }

    //Mark start vertex as seen
    seen[vertexPos] = true; 

    //While loop finds each vertex connected to our start vertex and adds to queue
    while(!breadthFirstSearch.empty()){
        visit(breadthFirstSearch.front()); //Display first vertex starting with our start vertex

        breadthFirstSearch.pop(); //remove from queue

        //For loop that adds each vertex connecting to our startPos and adds them to
        //queue if they haven't been seen before and an edge exits between them
        for(int i = 0; i < SIZE; i++){
            if(edgeWeightTracker[vertexPos][i] != 0 && (!seen[i])){
                start = vertexArray[i];
                breadthFirstSearch.emplace(start);
                seen[i] = true; 
            }
        }
        //Increment our vertexPos so we change our start vertex
        vertexPos++;
    }
}

/**********************************************
    This function is needed as our seen array needs to be reset if we
    call both traversal functions since the values we store in it stay
    even after the function finishes execution.
    @param none
    @return void (none)
**********************************************/
template<typename T>
void GRAPH<T>::resetSeen(){
     for(int i = 0; i < SIZE; i++){
        seen[i] = false; 
    }
}

template<typename T>
T GRAPH<T>::getVertex(int& pos) const{
    return vertexArray[pos];
}

template<typename T>
GRAPH<T>::~GRAPH(){

}