#include <iostream>
using namespace std;

class stack{
    private:
    int max=10;
    int arr[];
    public:
    stack(){
        max = 10;
        int arr[max];
    }
    stack(int n){
        max = n;
        int arr[max];
    }
    void push(int n){
        int i = 0;
        while (arr[i]!= '0'){
            i++;
        }
        arr[i] = n;
        arr[i+1] = '0';
    }
    void pop(int n){
        int i = 0;
        while (arr[i]!= '0'){
            i++;
        }
        arr[i-1] = '0';
    }
}