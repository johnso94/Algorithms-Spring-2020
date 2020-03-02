#include <iostream>
#include <vector>
#include "hw10-merge.h"
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2) {
    int len1 = arr1.size(); 
    int len2 = arr2.size(); // getting lengths
    int len3 = len1 + len2; // length of final arr is both previous lengths 
    vector<int> sorted; // initializing sorted list of size len3

    int pl1 = 0;
    int pl2 = 0;

    for (int i = 0; i < len3; i++) {
        //if ((arr1[pl1] < arr2[pl2]) || pl2 >= arr2.size()) { // if the top value of arr1 is less than arr2 OR we're done with arr2
        if (pl2 >= arr2.size()) { // if we're done with arr2
            sorted.insert(sorted.begin() + i, arr1[pl1]);
            pl1++; // increment placeholder by 1
        }
        //else if ((arr1[pl1] > arr2[pl2]) || pl1 >= arr1.size()) { // elif the top value of arr2 is less than arr1 OR we're done with arr1
        else if (pl1 >= arr1.size()) { // elif we're done with arr1
            sorted.insert(sorted.begin() + i, arr2[pl2]);
            pl2++; // increment placeholder by 1
        }
        else if (arr1[pl1] > arr2[pl2]) { // if the top value of arr2 is less than arr1
            sorted.insert(sorted.begin() + i, arr2[pl2]);
            pl2++; // increment placeholder by 1
        }
        else {
            sorted.insert(sorted.begin() + i, arr1[pl1]);
            pl1++;
        }
    }

    return sorted;
}