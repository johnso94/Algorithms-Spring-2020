#include<iostream>
#include<vector>

using namespace std;

//I did this project with Jacob and Panha

//creating some global variables
vector<vector<int>> visited;
int count;
int aMax = 10;
int bMax = 7;
int cMax = 4;
bool flag = true;

void pour(int a, int b, int c, vector<vector<int>> path){
    //checking if the new vector is already in visited
    vector<int> fresh = {a,b,c};
    for (vector<int> x : visited){
        if(x == fresh){
            return;
        }
    }
    //updating in to vector and count
    visited.push_back({a,b,c});
    ::count++;
    path.push_back({a,b,c});
    if(b == 2 || c == 2){
        flag = false;
        cout << "One path to get the right result is " ;
        for (vector<int> x : path){
            for (int y : x){
                cout << y << ' ';
            }
            cout << ", ";
        }
        cout << endl;
    }
    //pouring a to b
    int a1 = a;
    int b1 = b;
    int c1 = c;
    while (b1<bMax && a1 > 0){
        b1++;
        a1--;
    }
    pour(a1,b1,c1,path);
    //pouring a to c
    a1 = a;
    b1 = b;
    c1 = c;
    while (c1<cMax && a1 > 0){
        c1++;
        a1--;
    }
    pour(a1,b1,c1,path);
    //pouring b to a
    a1 = a;
    b1 = b;
    c1 = c;
    while (a1<aMax && b1 > 0){
        a1++;
        b1--;
    }
    pour(a1,b1,c1,path);
    //pouring b to c
    a1 = a;
    b1 = b;
    c1 = c;
    while (c1<cMax && b1 > 0){
        c1++;
        b1--;
    }
    pour(a1,b1,c1,path);
    //pouring c to a
    a1 = a;
    b1 = b;
    c1 = c;
    while (a1<aMax && c1 > 0){
        a1++;
        c1--;
    }
    pour(a1,b1,c1,path);
    //pouring c to b
    a1 = a;
    b1 = b;
    c1 = c;
    while (b1<bMax && c1 > 0){
        b1++;
        c1--;
    }
    pour(a1,b1,c1,path);
    return;
}

int main(){
    vector<vector<int>> v;
    pour(0,7,4,v);
    // cout << "The possible combinations are:" << endl;
    // for(vector<int> x: visited){
    //     cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
    // }
    if(flag){
        cout << "There are no routes which give the desired result" << endl;
    }
    return 0;
}