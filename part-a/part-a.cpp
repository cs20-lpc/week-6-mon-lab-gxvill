#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
//#include "function.hpp"
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

int findMaxRecTail(const int[], const int, int = 0);

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays, one fixed and the other
 * random. Determines the maximum value by calling the local function and the
 * standard function.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}

int findMaxRecTail(const int arr[], const int SIZE,int i){
    //base case (when we get to the end)
    if(i == SIZE){
        return arr[i];
    }

    //recursive case
    // call the function and increment i
    int comp = findMaxRecTail(arr, SIZE, i + 1);
    if(arr[i] > comp){
        return arr[i];
    }
    return comp;
}