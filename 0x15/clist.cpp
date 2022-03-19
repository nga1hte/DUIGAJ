#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class list{
    public:
    node *head;
    void create(int A[], int n);
    void display();
    void insertAt(int pos, int data);
    void del(int pos);
};

int main(){
    list a;
    int A[] = {1, 2, 3, 4, 5};
    a.create(A, 5);
    a.display();
    cout << endl;
    a.insertAt(0, 69);
    a.display();
    cout << endl;
    a.del(0);
    a.display();
    cout << endl;

}

void list::create(int A[], int n){
    int i;
    node *temp;
    node *last;
    head = new node();
    head->data = A[0];
    head->next = head;
    last = head;
    for(i = 1; i < n; i++){
        temp = new node();
        temp->data = A[i];
        temp->next = head;
        last->next = temp;
        last = last->next;
    }
}

void list::display(){
    node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

void list::insertAt(int pos, int data){
    int i;
    node *t = head;
    node *temp;
    temp = new node();
    temp->data = data;
    if(pos == 0){
        if(head == NULL){
            head = temp;
            head->next = head;
        }else{
            while(t->next != head){
                t = t->next;
            }
            temp->next = head;
            t->next = temp;
            head = temp;
        }

    }else{
        for(i = 1; i < pos; i++)
            t = t->next;
        temp->next = t->next;
        t->next = temp;
    }
}

void list::del(int pos){
    node *temp = head;
    if(pos < 0)
        return;
    if(pos == 0){
        node *p = head;
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        delete p;
    }else{
        node *p;
        for(int i = 1; i < pos; i++)
            temp = temp->next;
        p = temp; 
        temp = temp->next;
        p->next = temp->next;
        delete temp;
    }
}
