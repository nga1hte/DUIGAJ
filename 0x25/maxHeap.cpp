#include <iostream>
using namespace std;

class maxHeap{
    public:
    int *data;
    int max;
    int size;
    maxHeap(int max);
    void insert(int n); 
    void display();
    int deleteN();
    void heapifyMin();
};

maxHeap::maxHeap(int max){
    this->max = max;
    data = new int[max];
    size = -1;
}

void maxHeap::display(){
    for(int i = 0; i <= size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void maxHeap::insert(int n){
    int i;
    if(size+1 < max){
        i = ++size;
        data[i] = n;
    }else{
        cout << "Heap is already full!" << endl;
        return;
    }

    while(i > 0 && data[i%2 == 0 ? i/2 - 1 : i/2] < n){
        data[i] = data[i%2 == 0 ? i/2 - 1 : i/2];
        i = i%2 == 0 ? i/2 - 1 : i/2;
    }
    data[i] = n;
}

int maxHeap::deleteN(){
    int x, i, j;
    x = data[0];
    i = 0;
    j = 2*i+1;
    data[i] = data[size];
    int temp;
    while(j < size){
        if(data[j+1] > data[j]) 
            j = j+1;
        if(data[i] < data[j]){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i = j;
            j = 2*j+1;
        }else
            break;
    }
    data[size--] = x;
    return x;
}

void maxHeap::heapifyMin(){
    for(int i = (size+1)/2 - 1; i >= 0; i--){
        int j = 2 * i + 1;
        while(j < size+1){
            if(j < size && data[j] > data[j+1])
                j = j+1;

            if(data[i] > data[j]){
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i = j;
                j = 2 * i + 1;
            }else
                break;
        }
    }
}

int main(){
    maxHeap m(10);
    m.insert(10);
    m.insert(6);
    m.insert(8);
    m.insert(7);
    m.insert(9);
    m.insert(11);
    m.display();
    m.heapifyMin();
    m.display();
    return 0;
}
