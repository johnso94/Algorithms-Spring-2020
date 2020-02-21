#include<iostream>
using namespace std;

void recursive(int n = 2, int count = 0){
    int i = 0;
    while(i < 2*count){
        cout << ' ';
        i++;
    }
    cout << n << endl;
    if(n > 0){
        recursive(n/3,count+1);
        recursive(n/3,count+1);
        recursive(n/3,count+1);
        recursive(n/3,count+1);
        recursive(n/3,count+1);
    }
};

int main(){
    recursive();
    return 0;
}