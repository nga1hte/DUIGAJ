#include <iostream>
using namespace std;

class hashTable{
    public:
    int HT[10];
    hashTable();
    void insert(int key);
    int hash1(int key);
    int hash2(int key);
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

int hashTable::hash1(int key){
    return key % 10;
}

int hashTable::hash2(int key){
    return 7 - (key % 7);
}

void hashTable::insert(int key){
    int i = 0;
    int h1 = hash1(key);
    int h2 = hash2(key);
    while(HT[(h1+i*h2)%10] != -1){
        i++;
    }
    HT[(h1+i*h2)%10] = key;
}

int hashTable::search(int key){
    int i = 0;
    int h1 = hash1(key);
    int h2 = hash2(key);
    while(HT[(h1+i*h2)%10] != key){
        if(HT[(h1+i*h2)%10] == -1)
            return -1;
        i++;
    }
    return (h1+i*h2)%10;
}


int main(){
    int arr[] = {5, 25, 15, 35, 95};
    int size = sizeof(arr)/sizeof(arr[0]);
    hashTable H;

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    for(int i = 0; i < size; i++)
        H.insert(arr[i]);
    H.display();

    cout << "Searching for 23: ";
    cout << H.search(23) << endl;
    cout << "Searching for 5: ";
    cout << H.search(5) << endl;

}
