/**********************************************
    Program for CS302, meant to work with sorting algorithims. 
    This program will write out output to a file that includes the amount 
    of swaps, comparisons, as well as time stamps for how long each sort takes.
    This program will need reinditions. 
    @file main.cpp 
    @author Isaiah McLain 
    @version 1.0 3/27/2022
**********************************************/

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <math.h>
#include <fstream>
#include <chrono>

using namespace std::chrono;

//Prototypes 
template<typename T> 
void bubbleSort(T nums[], int size, std::ofstream &outFile); 

template<typename T>
void quickSort(T nums[], int low, int high, std::ofstream &outFile);

template<typename T>
int partition(T nums[], int low, int high, std::ofstream &outFile);

template<typename T> 
void selectionSort(T nums[], int size, std::ofstream &outFile); 

template<typename T>
void numberGenerator(T nums[], int size);

template<typename T> 
void printNums(const T nums[], int size);

template<typename T>
void resetNums(T nums[], int size, T reset[]);

template<typename T>
void setNums(T nums[], int size, T reset[]);


/**********************************************
    This function is the main driver of the program, it contains the functions calls
    to each sorting algorithim. It also contains the logic for calculating
    how much time each function call takes. It initilizes the three arrays needed for
    this project as well as File I/O handling.
    @param none
    @return int that tells program executed properly 
**********************************************/
int main(){
    //Creation of arrays to be used
    int numsThousand[1000]; 
    int numsTenThousand[10000];
    int numsHundredThousand[100000];
    int resetThousand[1000]; 
    int resetTenThousand[10000];
    int resetHundredThousand[100000];

    //File creation for data
    std::ofstream outFile;
    outFile.open("data1001.txt");
    if(outFile){
        std::cout << "open successful" << std::endl;
    }
    else{
        std::cerr << "couldnt write data" << std::endl;
    }

    outFile << "Use control F to search file for bubble sort." << std::endl;
    outFile << "Final quick sort value is true values, will be right above selection and bubble sort, bubble sort surrounded by ignore only used to sort data." << std::endl;
        //Unsorted each time
        numberGenerator(numsThousand, 1000);
        setNums(numsThousand, 1000, resetThousand);
        //Starts cpu time to completion clock
        auto start = high_resolution_clock::now();  
        quickSort(numsThousand, 0, 1000, outFile);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl; 
        resetNums(numsThousand, 1000, resetThousand);

        start = high_resolution_clock::now(); 
        selectionSort(numsThousand, 1000, outFile);
        stop = high_resolution_clock::now();  
        duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl; 
        resetNums(numsThousand, 1000, resetThousand); 

        start = high_resolution_clock::now(); 
        bubbleSort(numsThousand, 1000, outFile);
        stop = high_resolution_clock::now(); 
        duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl; 
        outFile << "unsorted each time done" << std::endl;
        
        
        //Sorted each time
        numberGenerator(numsThousand, 1000);
        setNums(numsThousand, 1000, resetThousand); 
        //Initial Sort, Data doesn't matter
        outFile << "IGNORE" << std::endl;
        bubbleSort(numsThousand, 1000, outFile);
        outFile << "IGNORE" << std::endl << std::endl << std::endl;
        
        //Matters
        start = high_resolution_clock::now(); 
        quickSort(numsThousand, 0, 1000, outFile);
        stop = high_resolution_clock::now(); 
        duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl; 

        start = high_resolution_clock::now(); 
        selectionSort(numsThousand, 1000, outFile); 
        stop = high_resolution_clock::now(); 
        duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl; 

        start = high_resolution_clock::now(); 
        bubbleSort(numsThousand, 1000, outFile);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        outFile << "Time duration for sort: " << duration.count() << std::endl;  
        outFile << "sorted each time done" << std::endl;
    
    return 0; 
}

/**********************************************
    This function is the bubble sort algoritihim and will
    sort the array through many iterations of bubble sorts.
    @param T nums[], int size, std::ofstream &outFile
    @return none (void) 
**********************************************/
template<typename T>
void bubbleSort(T nums[], int size, std::ofstream &outFile){
    int swaps{}; //Tracks swaps
    int compare{}; //Tracks comparisons
    //Bubble sort loop logic, could've used a swap function
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            compare++;
            if(nums[j] < nums[i]){
                T temp = nums[i]; 
                nums[i] = nums[j];
                nums[j] = temp;
                swaps++; 
            }
        }
    }
    outFile << "Bubble sort compares: " << compare << std::endl;
    outFile << "Bubble sort swaps: " << swaps << std::endl;
}

/**********************************************
    This function generates random values between 0 and 10^6 
    to fill the arrays with. Amount dependent on size
    @param T nums[], int size
    @return none (void)
**********************************************/
template<typename T>
void numberGenerator(T nums[], int size){
    srand((unsigned) time(0)); //Seeds random value to clock 
    int randNum{};
    int power = pow(10,6); //pow function same as 10 ^ 6

    for(int i = 0; i < size; i++){
        randNum = rand() % power; //Keeps numbers within range
        nums[i] = randNum; 
    } 

}

/**********************************************
    This function was a helper function for deugging purposes.
    Outputs array.
    @param const T nums[], int size
    @return none (void)
**********************************************/
template<typename T>
void printNums(const T nums[], int size){
    for(int i = 0; i < size; i++){
        std::cout << nums[i] << std::endl;
    }
}

/**********************************************
    This function uses the selection sort algorithim to sort through
    the array. Like the bubble sort it's internal.
    @param T nums[], int size, std::ofstream &outFile
    @return none (void)
**********************************************/
template<typename T>
void selectionSort(T nums[], int size, std::ofstream &outFile){
    int compare{};
    int swaps{};
    
    //iterates through loops to sort array
    for(int i = 0; i < size; i++){
        int smallIndex = i; 
        for(int j = i + 1; j < size; j++){
            compare++;
            if(nums[j] < nums[smallIndex]){
                smallIndex = j; 
            }
        }
        T temp = nums[i];
        nums[i] = nums[smallIndex];
        nums[smallIndex] = temp;
        swaps++;
    }

    outFile << "Selection sort compares: " << compare << std::endl;
    outFile << "Selection sort swaps: " << swaps << std::endl;
}

/**********************************************
    This function is part of the recursive functions that implement
    the quick sort algorithim. This function calls itself as well as
    the partition function in order to sort the array. 
    @param const T nums[], int low, int high, std::ofstream &outFile
    @return none (void)
**********************************************/
template<typename T>
void quickSort(T nums[], int low, int high, std::ofstream &outFile){
    if(low < high){
        //Pivot used later in sorting to determine where to compare and start from
        int pivot = partition(nums, low, high, outFile);
        quickSort(nums, low, pivot - 1, outFile);
        quickSort(nums, pivot + 1, high, outFile);
    }
}

/**********************************************
    This function is part of the recursive functions that implement
    the quick sort algorithim. This function handles he swapping of elements
    in order to sort the array. (Currently has issue of making first 
    value 0 and forgoing the largest number)
    @param const T nums[], int low, int high, std::ofstream &outFile
    @return none (void)
**********************************************/
template<typename T>
int partition(T nums[], int low, int high, std::ofstream &outFile){
    int pivot = nums[high];
    int i = (low - 1);
    static int compare{}; //Static in this case due to recursive nature, something to fix later on
    static int swaps{};
    
    for(int j = low; j < high; j++){
        compare++;
        if(nums[j] <= pivot){
            i++;
            T temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            swaps++;
        } 
    }
    T temp = nums[i + 1];
    nums[i + 1] = nums[high];
    nums[high] = temp;
    swaps++;

    outFile << "Quick sort compares unsorted: " << compare << std::endl;
    outFile << "Quick sort swaps unsorted: " << swaps << std::endl;

    return (i + 1);
}

/**********************************************
    This function is a helper function used to reset the array
    back to it's randomized order it had when we first started the 
    program, this is so each sorting algorithim deals with the same set of
    numbers.  
    @param const T nums[], int size, T reset[]
    @return none (void)
**********************************************/
template<typename T>
void resetNums(T nums[], int size, T reset[]){
    for(int i = 0; i < size; i++){
        nums[i] = reset[i]; 
    }
}

/**********************************************
    This function is a helper function used to set the temporary 
    array known as reset to have the randomized values that are within
    nums[] to later be used to reassign the randomized values to nums[]. 
    @param const T nums[], int size, T reset[]
    @return none (void)
**********************************************/
template<typename T>
void setNums(T nums[], int size, T reset[]){
    for(int i = 0; i < size; i++){
        reset[i] = nums[i]; 
    }
}