#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class stack{
    public:
        node *s;

        stack(){
            s = NULL;
        }

        ~stack(){
            node *p = s;
            while(s){
                s = s->next;
                delete p;
                p = s;
            }
        }

        void push(int x);
        int pop();
        int peek(int n);
        int stackTop();
        int isEmpty();
        int isFull();
};

int main(){
    stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    cout << S.pop() << endl;
    cout << S.peek(2) << endl;
    cout << S.stackTop() << endl;
    return 0;
}

void stack::push(int x){
    node *temp = new node();
    if(temp == NULL)
        cout << "Stack overflow!" << endl;
    else{
        temp->data = x;
        temp->next = s;
        s = temp;
    }
}

int stack::pop(){
    node *temp = s;
    int data = -1;
    if(!isEmpty()){
        data = temp->data;
        s = s->next;
        delete temp;
    }
    return data; 
}

int stack::peek(int n){
    node *p = s;
    for(int i = 0; p != NULL && i < n-1; i++){
        p = p->next;
    }
    if(p != NULL)
        return p->data;
    else
        return -1;
}

int stack::stackTop(){
    return s->data;
}

int stack::isEmpty(){
    if(s == NULL)
        return 1;
    return 0;
}

int stack::isFull(){
    node *t = new node();
    int r = t ? 1 : 0;
    delete t;
    return r;
}


