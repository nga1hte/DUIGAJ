#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class list{
    public:
    node *l;
    list();
    void display();
    void insert(int data);
    void insertAt(int post, int data);
    int count();
    node *search(int data);
    void Delete(int pos);
    int checkSorted();
    void removeDup();
    void reverse();
    void rreverse(node *p, node *q);
    void merge(node *b);
    int checkLoop();
};

list::list(){
    l = NULL;
}

void list::insert(int data){
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(l == NULL)
        l = temp;
    else{
        temp->next = l;
        l = temp;
    }
}

void list::display(){
    node *temp = l;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void list::insertAt(int pos, int data){
    node *temp = l;
    if(pos < 0 || pos > count()){
        cout << "Cannot insert to list" << endl;
        return;
    }else{
        node *tmp = new node();
        tmp->data = data;
        tmp->next = NULL;
        if(pos == 0){
            tmp->next = l;
            l = tmp;
            return;
        }
        for(int i = 0; i < pos; i++)
            temp = temp->next;

        tmp->next = temp->next;
        temp->next = tmp;

    }
}

int list::count(){
    int count = 0;
    node *temp = l;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

node *list::search(int data){
    node *temp = l;
    while(temp != NULL){
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void list::Delete(int pos){
    node *temp = l;
    node *p = temp;
    if(pos < 0 || pos > count()-1){
        cout << "Cannot delete item" << endl;
        return;
    }else{
        if(pos == 0){
            l = temp->next;
            delete temp;
            return;
        }
        for(int i = 0; i < pos; i++){
            p = temp;
            temp = temp->next;
        }
        p->next = temp->next;
        delete temp;
    }
}

int list::checkSorted(){
    node *temp = l->next;
    int prev = l->data;
    while(temp != NULL){
        if(prev > temp->data)
            return 0;
        prev = temp->data;
        temp = temp->next;
    }
    return 1;
}

void list::removeDup(){
    node *p = l;
    node *q = p->next;
    while(q != NULL){
        if(p->data == q->data){
            p->next = q->next;
            delete q;
            q = p->next;
            continue;
        }
        p = q;
        q = q->next;
    }
}

void list::reverse(){
    node *tmp = l;
    node *p = NULL;
    node *q = NULL;
    while(tmp != NULL){
        q = p;
        p = tmp;
        tmp = tmp->next;
        p->next = q;
    }
    l = p;
}

void list::rreverse(node *p, node *q){
    if(q != NULL){
        rreverse(q, q->next);
        q->next = p;
    }else{
        l = p;
    }
}

void list::merge(node *b){
    node *a = l;
    node *c = NULL;

    while(a != NULL && b != NULL){
        if(c == NULL){
            if(a->data < b->data){
                c = a;
                a = a->next;
            }else{
                c = b;
                b = b->next;
            }

            c->next = NULL;
            l = c;
        }
        if(a->data < b->data){
            c->next = a;
            a = a->next;
            c = c->next;
            c->next = NULL;
        }else{
            c->next = b;
            b = b->next;
            c = c->next;
            c->next = NULL;
        }
    }

    while(a != NULL){
        c->next = a;
        a = a->next;
        c = c->next;
        c->next = NULL;
    }

    while(b != NULL){
        c->next = b;
        b = b->next;
        c = c->next;
        c->next = NULL;
    }
}

int list::checkLoop(){
    node *p = l;
    node *q = l;
    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    }while(p && q && p != q);

    if(p == q)
        return 1;
    else 
        return 0;
}

int main(){
    list a;
    list b;

    a.insert(6);
    a.insert(5);
    a.insert(3);
    a.insert(1);
    a.display();

    b.insert(7);
    b.insert(4);
    b.insert(2);
    b.display();

    a.merge(b.l);
    a.display();
    node *temp = a.l;
    while(temp->next != NULL){
        temp = temp->next;
    }
    //temp->next = a.l;
    cout << (a.checkLoop()? "Loop" : "Not loop") << endl;
}
