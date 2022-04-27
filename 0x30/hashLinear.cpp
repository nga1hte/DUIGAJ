#include <iostream>
using namespace std;

class hashTable{
    public:
    int HT[10];
    hashTable();
    void insert(int key);
    int hash(int key);
    int search(int key);
    void display();
};

hashTable::hashTable(){
    for(int i = 0; i < 10; i++)
        HT[i] = -1;
}

void hashTable::display(){
    for(int i = 0; i < 10; i++)
        cout << HT[i] << " ";
    cout << endl;
}

int hashTable::hash(int key){
    return key % 10;
}

void hashTable::insert(int key){
    int i = 0;
    int h = hash(key);
    while(HT[(h+i)%10] != -1){
        i++;
    }
    h = (h+i)%10;
    HT[h] = key;
}

int hashTable::search(int key){
    int i = 0;
    int h = hash(key);
    while(HT[(h+i)%10] != key){
        if(HT[(h+i)%10] == -1)
            return -1;
        i++;
    }
    h = (h+i)%10;
    return h;
}


int main(){
    int arr[] = {1, 11, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    hashTable H;

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    for(int i = 0; i < size; i++)
        H.insert(arr[i]);
    H.display();

    cout << "Searching for 2: ";
    cout << H.search(2) << endl;
    cout << "Searching for 5: ";
    cout << H.search(5) << endl;

}
