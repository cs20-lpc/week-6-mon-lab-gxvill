#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}

void towerHanoi(int n, string curr, string r2, string r3, int& moves){
    // in my mind the leftmost input string is the current rod (and the one we want to move to)
    if(n == 0){
        return; 
    }

    towerHanoi(n-1, curr, r3, r2, moves);

    moves++;
    cout << "Moving disc " << n << " from " << curr << " to " << r3 << endl;

    towerHanoi(n-1, r2, curr, r3, moves);
}

/* thought process: (moves is always (2^n) - 1)
this needs to be a recursive function, calling the recursive function for every move basically

what is the base case?:
0 moves (no disks to move)

recursive case (n-1 disks are moved to the middle rod leaving nth rod to me moved to the last rod)

each recursive call should decrement n by 1 but keep passing the number of moves

example:

if we have n = 5 and want to get all 5 to rod 3, first we need to get 1-4 to rod 2, and if we need to get 1-4 to rod 2,
we first need to get 1-3 to rod 3. Does this make sense? yes, but how do i implement this?

recursively make a move at each base case. 


*/