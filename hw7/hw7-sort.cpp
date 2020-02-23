#include <iostream>
using namespace std;
#include <vector>
#include<stdlib.h>
#include"elapsed_time.h"


int main(){

    //seed the random number generator
    int seed;
    cout << "Enter a random int seed: ";
    cin >> seed;
    srand(seed);

    //create array
    const int len = 100;
    int arr[len];
    for ( int i=0; i<len; i++ ) arr[i] = rand()%100;

    //print original
    cout << "Original Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    //copy array into vector in correct order
    start_timer();                              //START TIMER
    vector<int> v = {arr[0]};
    for(int a = 1; a < len; a++){
        int i;
        for(i = 0; i < v.size(); i++){
            if (v[i] > arr[a]){
                v.insert(v.begin() + i, arr[a]);
                break;
            }
        }
        if(i == v.size()){
            v.push_back(arr[a]);
        }
    }

    //copy back into original array
    for(int i = 0; i < len; i++){
        arr[i] = v[i];
    }
    double cycles = elapsed_time();     //END TIMER
    //print new array
    cout << "New Array: ";
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;

    cout << "Cycles: " << cycles << endl;

}