#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {2, 3, 5, 7, 11};
    for (int i = 0; i < 5; ++i){
        cout << v[i] << endl;
    }
    for (int x : v) {
        cout << x << endl;
    }
    cout << v.size() << endl;
    return 0;
}
//Pushback adds an element to the end of the vector
//erase gets rid of a specific element in the list
//clear gets rid of everything in the list
//insert places an element in a specific place