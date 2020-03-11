#include <iostream>
#include"elapsed_time.h"
using namespace std;

class Stack
{
    int max;
    int top = -1;
    int *items;
    void increment_size(){
        max = max + 100;
        int * list = new int[max];
        for(int i = 0; i < max-1; i++){
            list[i] = items[i];
        }
        delete items;
        items = list;
    }
public:
    Stack(int);
    Stack();
    void peek();

    void pop();
    void push(int);
    void see_all();
    ~Stack(){
        delete items;
    }
};

Stack::Stack(int x)
{
    max = x;
    items = new int[x];
}
Stack::Stack()
{
    max = 10;
    items = new int[10];
}
void Stack::push(int n)
{
    if (top >= max-1){
        cout << "The stack is too full to add " << n << "! Incrementing stack size!\n";
        increment_size();
        items[++top] = n;
    }
    else{
        items[++top] = n;
    }
}
void Stack::pop()
{
    if (top<0){
        cout << "The stack is already empty!\n";
    }
    else{
        cout << "Popped " << items[top--] << endl;
    }
}
void Stack::peek(){
    cout << "The top of the stack is " << items[top] << endl;
}
void Stack::see_all()
{
    for(int i = 0; i <= top; i++){
        cout << items[i] << ' ';
    }
    cout << endl;
}

int main()
{
    start_timer();

    int n = 1000000;
    Stack pile(n);
    for(int i = 0; i < n;i++){
        pile.push(i);
    }
    pile.see_all();

    double cycles = elapsed_time();  // also from elapsed_time.h

    cout << " Total cycles: " << cycles << endl;

    // Stack stack(2);
    // stack.push(5);
    // stack.push(4);
    // stack.push(3);
    // stack.push(9);
    // stack.see_all();
    // stack.pop();
    // stack.peek();
    return 0;
}