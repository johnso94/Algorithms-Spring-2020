#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// I worked with Panha Son on this section of the code

int main(){
    ifstream file;
    file.open("input.txt");
    //managing the first line
    string first;
    string second;
    file >> first;
    file >> second;
    int vertices;
    int edges;
    file >> vertices;
    file >> edges;
    cout << vertices << " " << edges << endl;
    //everything else
    vector<int> column1;
    vector<int> column2;
    for(int i = 0;i<edges;i++){
        int a,b;
        file >> a;
        file >> b;
        column1.push_back(a);
        column2.push_back(b);
    }
    for(int x:column1){
        cout << x << " ";
    }
    cout << endl;
    for(int x:column2){
        cout << x << " ";
    }
    cout << endl;
    vector<vector<int>> vectors;
    for(int i = 0; i < vertices; i++){
        vectors.push_back({});
    }
    //cout << "Test0" << endl;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            (vectors[i]).push_back(0);
        }
    }
    //cout << "Test1" << endl;
    for(int i = 0; i < edges; i++){
        int a = column1[i];
        int b = column2[i];
        vectors[a][b] = 1;
    }
    for(int i = 0; i < edges; i++){
        int a = column2[i];
        int b = column1[i];
        vectors[a][b] = 1;
    }
    //cout << "Test2" << endl;
    for(vector<int> v: vectors){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}