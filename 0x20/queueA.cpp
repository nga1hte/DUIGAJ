#include <iostream>
using namespace std;

class queue{
    public:
    int size;
    int *q;
    int head;
    int tail;

    queue(int s){
        size = s;
        q = new int[s];
        head = 0;
        tail = 0;
    }

    void enqueue(int data);
    int dequeue();
    int isFull();
    int isEmpty();
};

int main(){
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.dequeue();
    q.enqueue(9);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.dequeue() << endl;

}

void queue::enqueue(int data){
    if(!isFull()){
        tail = (tail+1)%size;
        q[tail] = data;
    }else{
        cout << "Queue is full!" << endl;
        return;
    }
}

int queue::dequeue(){
    if(!isEmpty()){
        head = (head+1)%size;
        return q[head];
    }else{
        cout << "Queue is empty!" << endl;
        return -1;
    }
}

int queue::isFull(){
    if((tail+1)%size == head)
        return 1;
    return 0;
}

int queue::isEmpty(){
    if(tail == head)
        return 1;
    return 0;
}
