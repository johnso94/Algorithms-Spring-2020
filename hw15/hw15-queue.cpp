#include <iostream>
using namespace std;

class Queue
{
private:
    int max;
    int top = -1;
    int bottom = -1;
    int * items;
public:
    Queue();
    Queue(int);
    void inject(int);
    void retrieve();
    ~Queue(){
        delete items;
    }
};

Queue::Queue(){
    max = 10;
    items = new int[10];
}
Queue::Queue(int x){
    max = x;
    items = new int[x];
}

void Queue::inject(int x){
    if(top < max){
        cout << "inject in " << x << endl;
        items[++top] = x;
    }
    else{
        cout << "The queue is full!\n" << top << max << endl;
    }
}
void Queue::retrieve(){
    if (bottom < top){
        cout << "Retrieving " << items[++bottom] << endl;
    }
    else{
        cout << "The queue is empty!\n";
    }
}













int main()
{
    Queue escalator(4);
    escalator.inject(7);
    escalator.inject(8);
    escalator.retrieve();
    escalator.inject(9);
    escalator.inject(10);
    escalator.inject(11);
    escalator.retrieve();
    escalator.retrieve();
    escalator.retrieve();
    escalator.retrieve();
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