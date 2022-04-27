#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class hashTable{
    public:
    node **HT;
    hashTable();
    int hash(int key);
    void insert(int key);
    int search(int key);
    ~hashTable();
};

hashTable::hashTable(){
    HT = new node *[10];
    for(int i = 0; i < 10; i++)
        HT[i] = nullptr;
}

int hashTable::hash(int key){
    return key%10;
}

void hashTable::insert(int key){
    int h = hash(key);
    node *temp = new node();
    temp->data = key;
    temp->next = nullptr;
    if(HT[h] == nullptr)
        HT[h] = temp;
    else{
        node *p = HT[h];
        node *q = HT[h];
        while(p && p->data < key){
            q = p;
            p = p->next;
        }
        if(q == HT[h]){
            temp->next = HT[h];
            HT[h] = temp;
        }else{
            temp->next = q->next;
            q->next = temp;
        }
    }
}

int hashTable::search(int key){
    int h = hash(key);
    node *p = HT[h];
    while(p){
        if(p->data == key)
            return p->data;
        p = p->next;
    }
    return -1;
}

hashTable::~hashTable(){
    for(int i = 0; i < 10; i++){
        node *p = HT[i];
        while(HT[i]){
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete []HT;
}

int main(){
    int arr[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(arr)/sizeof(arr[0]);
    hashTable H;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
        H.insert(arr[i]);
    cout << "Searching for 6: ";
    cout << H.search(6) << endl;
    cout << "Searching for 7: ";
    cout << H.search(7) << endl;
    return 0;
}
