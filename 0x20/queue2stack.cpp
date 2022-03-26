#include <iostream>
using namespace std;
#include "../0x18/stack.h"

class queue{
    public:
    stack in;
    stack out;

    void enqueue(int data);
    int dequeue();
};

void queue::enqueue(int data){
    in.push(data);
}

int queue::dequeue(){
    if(in.isEmpty() && out.isEmpty()){
        cout << "Queue is empty!" << endl;
        return -1;
    }else{
        if(out.isEmpty()){
            int data;
            while(!in.isEmpty()){
                data = in.pop();
                out.push(data);
            }
        }
        return out.pop();
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
    q.enqueue(1);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;


}
