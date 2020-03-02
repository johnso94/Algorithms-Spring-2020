#include <iostream>
#include <vector>
#include <cstdlib>
#include "hw10-merge.cpp"
#include "elapsed_time.h"
using namespace std;

// I partnered with Agustin Forero in this section.

vector<int> mergesort(vector<int> v){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    int i = 1;
    if (v.size() > 1){
        for(int x : v){
            if (i == 1){
                v1.push_back(x);
            }
            else{
                v2.push_back(x);
            }
            i *= -1;
        }
        v1 = mergesort(v1);
        v2 = mergesort(v2);
        v3 = merge(v1,v2);
    }
    else{
        v3.push_back(v.front());
    }
    return v3;
}

int main(){
    start_timer();
    vector<int> v;
    for (int i = 0; i < 1000000; i++) {
        v.push_back(rand() % 10000);
    }
    vector<int> v2;
    v2 = mergesort(v);

    double cycles = elapsed_time();
    cout << "This operation took " << cycles << " cycles to complete." << endl;

    // TIME ELAPSED:
    // this program took 1.4856e+10 cycles to complete.

    /* this is overkill, just know that it works lmao
    for (int x : v2){
        cout << x << ' ';
    }
    cout << endl;
    */

    return 0;
}