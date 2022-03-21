#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
};

class list{
    public:
    node *head;
    node *tail;
    void create(int A[], int n);
    void display();
    void displayT();
    void insertAt(int pos, int data);
    void del(int pos);
    void reverse();
    void midp(node *p);
    void midP(node *p, node *q);
};

int main(){
    list a;
    int A[] = {1, 2, 3, 4, 5, 6};
    a.create(A, 6);
    a.display();
    a.displayT();
    a.insertAt(3, 69);
    a.display();
    a.displayT();
    a.del(3);
    a.display();
    a.displayT();
    a.reverse();
    a.display();
    a.midP(a.head, a.head);
}

void list::create(int A[], int n){
    int i;
    node *temp;
    node *p;
    head = new node();
    head->data = A[0];
    head->next = head;
    head->prev = NULL;
    p = head;
    for(i = 1; i < n; i++){
        temp = new node();
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = p;
        p->next = temp;
        p = p->next;
    }
    tail = temp;
}

void list::display(){
    node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != NULL);
    cout << endl;
}

void list::displayT(){
    node *temp = tail;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void list::insertAt(int pos, int data){
    node *temp = new node();
    node *p = head;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if(pos == 0){
        temp->next = head;
        head->prev = temp;
        head = temp;
    }else{
        for(int i = 1; i < pos; i++){
            p = p->next;
        }

        temp->next = p->next;
        temp->prev = p;
        if(p->next)
            p->next->prev = temp;
        else
            tail = temp;
        p->next = temp;
    }
}

void list::del(int pos){
    node *temp = head;
    node *p = head;
    if(pos == 0){
        head = head->next;
        delete temp;
        if(head)
            head->prev = NULL;
    }else{
        for(int i = 1; i < pos; i++){
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        if(p->next)
            p->next->prev = p;
        else
            tail = p;
        delete temp;
    }
}

void list::reverse(){
    node *p = head;
    tail = head;
    node *temp;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if(p->prev == NULL)
            head = p;
        p = p->prev;
    }
}

void list::midp(node *p){
    static int count;
    static int mid;
    if(p == NULL){
        return;
    }else{
        count++;
        mid = count/2;
        midp(p->next);
        if(--count == mid)
            cout << "Mid: " <<  p->data << endl;
    }
        
}

void list::midP(node *p, node *q){
    if(q == NULL)
        cout << p->data << endl;
    else if(q->next == NULL)
        midP(p, q->next);
    else
        midP(p->next, q->next->next);
}


