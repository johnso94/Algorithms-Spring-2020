#include <iostream>
using namespace std;

class node
{ 
    public:
    int value;
    node * next;
    node(int n){
        value = n;
        next = NULL;
    }
    node(){
        next = NULL;
    }
    void set_next(node n)
    {
        next = &n;
    }
};

class Stack
{
private:
    int length = 0;
    // node * Top;
public: 
    node starter;
    // Stack(){
    //     node * Top = &starter;
    // }
    void push(int);
    void pop();

    void see_all();
    ~Stack();
};

void Stack::push(int x)
{
    node * Temp = new node;
    Temp->value = x;

    // Top -> next = &Temp;
    // Top = &Temp;

    node * star = &starter;
    while (star->next != NULL){
        star = star->next;
    }
    star->next = Temp;
    length++;
}

void Stack::pop(){
    node * star = &starter;
    if (length >0){
        for (int i = 0; i < length-1; i++){
            star = (* star).next;
        }
        delete star-> next;
        (*star).next = NULL;
        length--;
    }
    else
    {
        cout << "There are no elements left in the list.\n";
    }
}

void Stack::see_all()
{
    if(length > 0){
        node * star = starter.next;
        while ( star->next != NULL){
            cout << star->value << ' ';
            star = star->next;
        }
        cout << star->value << ' ';
        cout << '\n';
    }
    else{
        cout << "There are no elements in the list.\n";
    }

}
Stack::~Stack(){
    while(starter.next != NULL)
    {
        pop();
    }
}

int main(){
    Stack stack;
    //stack.pop();
    stack.push(5);
    stack.see_all();
    stack.push(10);
    stack.push(20);
    stack.see_all();
    stack.pop();
    stack.see_all();
    return 0;
}