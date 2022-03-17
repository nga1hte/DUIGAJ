#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(){
            data = 0;
            next = NULL;
        }
};

void create(node *a, int n){
    cout << "n: ";
    cin >> a->data;
    for(int i = 1; i < n; i++){
        node *temp = new node();
        cout << "n: ";
        cin >> temp->data;
        temp->data;
        temp->next = NULL;
        a->next = temp;
        a = temp;
    }
}

void display(node *temp){
    if(temp == NULL)
        return;
    cout << temp->data << " ";
    display(temp->next);
}

int count(node *temp){
    if(temp == NULL)
        return 0;
    else 
        return 1 + count(temp->next);
}

int sum(node *temp){
    if(temp == NULL)
        return 0;
    else
        return temp->data + sum(temp->next);
}

int max(node *temp){
    int max = temp->data;
    while(temp != NULL){
        if(temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}


int rmax(node *temp){
    int x = -32;
    if(temp == NULL)
        return x;
    x = rmax(temp->next);
    return ((x > temp->data) ? x : temp->data);
}

node* linearSearch(node *temp, int data){
    while(temp != NULL){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

node *rlinearSearch(node *temp, int data){
    if(temp == NULL)
        return NULL;
    if(temp->data == data)
        return temp;
    return rlinearSearch(temp->next, data);
}

node *linearS(node **first, int data){
    node *temp = *first;
    node *q = NULL;
    while(temp != NULL){
        if(temp->data == data){
            q->next = temp->next;
            temp->next = *first;
            *first = temp;
            break;
        }
        q = temp;
        temp = temp->next;
    }
    return temp;
}

node *insert(node *s, int data, int pos){
    node *temp = new node();
    temp->data = data;
    node *start = s;
    if(pos == 1){
        temp->next = s;
        return temp;
    }
    for(int i = 0; i < pos - 1; i++){
        s = s->next;
    }
    temp->next = s->next;
    s->next = temp;
    return start;
}

void insertAtLast(node *s, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(s == NULL)
        s = temp;
    while(s->next != NULL)
        s = s->next;
    s->next = temp;
}

void insertAtSorted(node *s, int data){
    node *temp = new node();
    temp->data = data;
    node *q = NULL;
    if(s == NULL){
        s->data = data;
        s->next = NULL;
    }

    while( s && data >= s->data){
        q = s;
        s = s->next;
    }
   
    temp->next = s;
    q->next = temp;
}

int main(){
    node *a = new node();
    create(a, 5);
    display(a);
    cout << endl;
    cout << "length: " << count(a) << endl;
    display(a);
    cout << endl;
    a = insert(a, 69, 5);
    display(a);
    cout << endl;
    insertAtLast(a, 420);
    display(a);
    cout << endl;
    insertAtLast(a, 69420);
    display(a);
    cout << endl;
    insertAtSorted(a, 66);
    display(a);
    cout << endl;
}

