#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream file;
    file.open("input2.txt");
    //resusing the code from the part to get an adjacency list
    string first;
    string second;
    file >> first;
    file >> second;
    int vertices;
    int edges;
    file >> vertices;
    file >> edges;

    vector<int> column1;
    vector<int> column2;
    for(int i = 0;i<edges;i++){
        int a,b;
        file >> a;
        file >> b;
        column1.push_back(a);
        column2.push_back(b);
    }
    cout << endl;
    vector<vector<int>> vectors;
    for(int i = 0; i < vertices; i++){
        vectors.push_back({});
    }

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            (vectors[i]).push_back(0);
        }
    }

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
    for(vector<int> v: vectors){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    //The new stuff
    int count = 0;
    vector<bool> visited;
    vector<int> previsit;
    vector<int> postvisit;
    for (int i = 0; i < vertices; i++){
        visited.push_back(0);
        previsit.push_back(-1);
        postvisit.push_back(-1);

    }

    vector<int> stack;
    //int seeking = NULL; // the value we're looking for
    int current = 0;
    stack.push_back(current);
    visited[stack.back()] = 1;
    previsit[stack.back()] = count;
    while(!stack.empty()){
        bool flag = 1;
        count++;
        for(int i = 0; i < vertices; i++){
            if(vectors[stack.back()][i] == 1 && !visited[i]){
                stack.push_back(i);
                visited[i] = 1;
                previsit[i] = count;
                flag = 0;
                break;
            }
        }
        if (flag){
            postvisit[stack.back()] = count;
            stack.pop_back();
        }
        for(int x:stack){
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << "The nodes you can get to from " << current << " are ";
    for(int i=0;i < vertices; i++){
        if(visited[i]){
            cout << i << ' ';
        }

    }
    cout << endl;
    return 0;
}