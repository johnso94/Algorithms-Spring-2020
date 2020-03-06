#include <iostream>
#include <vector>
#include <cstdlib>
#include "hw10-merge.cpp"

using namespace std;

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

int returnval(int arr[], int len, int seeking){
    int i = len/2 + 1;
    while(arr[i]!=seeking){
        if (arr[i] < seeking){
            i = (i+len+1)/2;
        }
        else if(i == len - 2){
            i = len -1;
        }
        else if(i == 1){
            i = 0;
        }
        else{
            i = (i+1)/2;
        }
    }
    return i;
}

int main(){
    int length = 100;
    vector<int> v;
    int array[length];
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
    //mergesort is set up to interact with a vector so we need to set it up as a vector
    for(int i = 0;i<length;i++){
        v.push_back(array[i]);
    }
    v = mergesort(v);
    int i = 0;
    for(int x : v){
        array[i]=x;
        i++;
    }
    for(int j = 0;j<length;j++){
        cout << array[j] << ' ';
    }
    cout << endl;
    int randint = array[(rand()+7) % length];
    cout << "The program is looking for " << randint << endl;
    int q = returnval(array,length,randint);
    cout << randint << " was found at index " << q << endl;
    return 0;
}