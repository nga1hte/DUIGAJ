#include <iostream>
using namespace std;

class de_queue{
    public:
    int *q;
    int head;
    int tail;
    int size;
    
    de_queue(int s){
        size = s;
        q = new int[s];
        tail = -1;
        head = -1;
    }
    void tenqueue(int data);
    int hdequeue();

    void henqueue(int data);
    int tdequeue();
};


int de_queue::hdequeue(){
    if(head == tail){
        cout << "Queue is empty" << endl;
        return -1;
    }else{
        return q[++head];
    }
}

int de_queue::tdequeue(){
    if(head == tail){
        cout << "Queue is empty" << endl;
        return -1;
    }else{
        return q[tail--];
    }
}

void de_queue::henqueue(int data){
    if(!( head == -1)){
        q[head--] = data;
    }else
        cout << "Queue is full" << endl;
}



void de_queue::tenqueue(int data){
    if(!(tail == size-1)){
        q[++tail] = data;
    }else
        cout << "Queue is full" << endl;
}


int main(){
    de_queue q(5);
    q.tenqueue(1);
    q.tenqueue(2);
    q.tenqueue(3);
    cout << q.tdequeue() << endl;
    cout << q.tdequeue() << endl;
    cout << q.tdequeue() << endl;
}



