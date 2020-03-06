#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;
char getFirstChar(string word){
    char ch = word[0];
}
map <char, int> order;
int returnval(vector<string> v, int len, string seeking){
    int i = len/2 + 1;
    while(v[i]!=seeking){
        if (order[getFirstChar(v[i])] < order[getFirstChar(seeking)]){
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

void setmap(map <char,int> order){
    order['A'] = 1;
    order['B'] = 2;
    order['C'] = 3;
    order['D'] = 4;
    order['E'] = 5;
    order['F'] = 6;
    order['G'] = 7;
    order['H'] = 8;
    order['I'] = 9;
    order['J'] = 10;
    order['K'] = 11;
    order['L'] = 12;
    order['M'] = 13;
    order['N'] = 14;
    order['O'] = 15;
    order['P'] = 16;
    order['Q'] = 17;
    order['R'] = 18;
    order['S'] = 19;
    order['T'] = 20;
    order['U'] = 21;
    order['V'] = 22;
    order['W'] = 23;
    order['X'] = 24;
    order['Y'] = 25;
    order['Z'] = 26;
}

int main(){
    int length = 5;
    vector<string> v = {"apple", "banana", "celery", "grape", "pear"};
    map <char, int> order;
    setmap(order);
    string seeking = "pear";

    int q = returnval(v, length, seeking);
    cout << "The index of " << seeking << " is " << q << endl;
    return 0;
}