//There are 7 + 1 + 1/3 + 2 + (1+1+1 + 3*1/3 + 2) * 100 + 1 + 20 = 631 1/3 cycles
#include<iostream>
using namespace std;

int main(){
    int x = 0;
    while(x < 200){
        y = 3;
        y *= 4;
        x += 2;
    }
    return 0;
}