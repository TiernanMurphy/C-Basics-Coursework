/**
 * file:            BubbleSort.cpp
 * author:          your name
 * date modified:   you fill in
 * description:     you fill in
 * 
 */

/*  NOTE:   Do not modify main.
 *          You are not allowed any additional #includes.
 *          You are not allowed to write any additional functions
 *              that are not specified in the .h file.
 *          The only outside function you're allowed to use is rand()
 *              within the fillArray function.
 */

#include<iostream>
#include "BubbleSort.h"

using namespace std;


int main(){

    srand(time(NULL));

    int myArray[10];

    fillArray(myArray, 10, 0, 100);

    cout << "~~~~~Before Sorting~~~~~" << endl;
    printArray(myArray, 10);
    doSort(myArray, 10);

    cout << "~~~~~After Sorting~~~~~" << endl;
    printArray(myArray, 10);

    return 0;
}





