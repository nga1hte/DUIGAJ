#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class queue{
    public:
    node *head;
    node *tail;
    queue(){
        head = NULL;
        tail = NULL;
    }

    void enqueue(int data);
    int dequeue();
    int empty();
    int full();
};

int queue::empty(){
    return ((head == NULL) ? 1 : 0);
}

int queue::full(){
    node *temp = new node();
    return ((temp == NULL) ? 1 : 0);
}

void queue::enqueue(int data){
    node *temp = new node();
    if(full()){
        cout << "Queue is full!" << endl;
    }else{
        temp->data = data;
        temp->next = NULL;
        if(empty()) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
    }
}

int queue::dequeue(){
    node *temp; 
    int data;
    if(empty()){ 
        cout << "Queue is empty" << endl;
        return -1;
    }else{
        temp = head;
        data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }

}

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;


}
