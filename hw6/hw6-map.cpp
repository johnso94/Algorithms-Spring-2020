#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string, int> price;
    price["socks"] = 1000;
    price["shoes"] = 3000;
    cout << price["socks"] << endl;  
    cout << price.size() << endl;
    for (auto p : price){
        cout << p.first << ' ' << p.second << endl;
    }

    if (price.find("shoes") == price.end()){
        cout << "not found" << endl;
    }
    price.erase("socks");
    for (auto p : price){
        cout << p.first << ' ' << p.second << endl;
    }
    price.clear();
    for (auto p : price){
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}
//price["something"] = else maps something to else
//The way that the map is set up maps strings to ints
//price.size returns the number of elements in price
//auto works to set up p for anything which is good because its holding
//two elements and the p:price sets p as the current element in price until
//p is empty
//p.first gets the first element of p
//price.find checks for something and if that element isn't there then
//it returns whatever is at price.end()
//price.erase gets rid of socks and its accossiated 
//price.clear() gets rid of everything in price