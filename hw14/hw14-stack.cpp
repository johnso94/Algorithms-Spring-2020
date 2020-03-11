#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> pile;
    pile.push(5);
    pile.push(4);
    pile.pop();
    cout << pile.top() << endl;
    return 0;
}