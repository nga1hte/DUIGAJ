#include <iostream>
using namespace std;

class stack{
    public:
        int size;
        int *S;
        int top;

        stack(int s){
            top = -1;
            size = s;
            S = new int[s];
        }

        void push(int x);
        int pop();
        int peek(int n);
        int isEmpty();
        int isFull();
};

int main(){
    stack a(5);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout << a.pop() << endl;
    cout << a.peek(2) << endl;
}

void stack::push(int x){
    if(!isFull())
        S[++top] = x;
    else
        cout << "Stack is full!" << endl;
}

int stack::pop(){
    int data;
    if(!isEmpty()){
        data = S[top];
        top--;
        return data;
    }else{
        cout << "Stack already empty!" << endl;
        return -1;
    }
    
}

int stack::isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}


int stack::isFull(){
    if(top == size - 1)
        return 1;
    return 0;
}

int stack::peek(int n){
    int index = top - n + 1;
    if(index <  0 ){
        cout << "invalid index" << endl;
        return -1;
    }
    return S[index];
}
