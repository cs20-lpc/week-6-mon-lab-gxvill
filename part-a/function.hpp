#define FUNCTION_H
#ifndef FUNCTION_H


int findMaxRecTail(const int arr[], const int SIZE, int i){
    //base case (when we get to the end)
    if(i == SIZE){
        return arr[i];
    }

    //recursive case
    // call the function and increment i
    int comp = findMaxRecTail(arr, SIZE, i ++);
    if(arr[i] > comp){
        return arr[i];
    }
    return comp;
}

#endif