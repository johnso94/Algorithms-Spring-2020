#include <iostream>
using namespace std;

class Stack
{
    int max;
    int top = -1;
    int *items;
    void double_size(){
        max = max * 2;
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
        cout << "The stack is too full to add " << n << "! Doubling stack size!\n";
        double_size();
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
    Stack stack(1);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.see_all();
    stack.pop();
    stack.peek();
    return 0;
}