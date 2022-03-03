#include <iostream>
using namespace std;

template <class T> 
class arr{
    private:
        T *A; 
        int size;
        int length;

    public:
        arr<T>(int n);
        void create();
        void display();
        void append(T x);
        void insert(int x, T n);
        T del(int x);
        int search(T x);
        int bs(T x);
        int binarySearch(T x, int l, int h);
        T get(int x);
        void set(int x, T n);
        void reverse();
        void shift();
        void rotate();
        void swap(T &a, T &b);
        
};   

template <class T>
arr<T>::arr(int n){
    size = n;
    A = new T[size];
}

template <class T>
void arr<T>::create(){
    int n;
    cout << "Enter the number of elements: " << flush;
    cin >> length;
    cout << "Enter the elements: " << endl;;
    for(int i = 0; i < length; i++){
        cout << i+1 << ": " << flush;
        cin >> A[i];
    }

}

template <class T>
void arr<T>::append(T x){
    if(length > size){
        cout << "Array is full!" << endl;
        return;
    }
    A[length] = x;
    length++;
}

template <class T>
void arr<T>::display(){
    cout << "List of the elements: " << endl;;
    for(int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << endl;

}

template <class T>
void arr<T>::insert(int x, T n){
    int i = length;
    if(x >= 0 && x < length){
        while(i > x){
            A[i] = A[i-1];
            i--;
        }
        A[x] = n;
        length++;
    }else cout << "Err: Cannot insert!" << endl;
}

template <class T>
T arr<T>::del(int x){
    int d = 0;
    int i = x;
    if(x >= 0 && x < length){
        d = A[x];
        while(i < length-1){
            A[i] = A[i+1];
            i++;
        }
        length--;
    }else cout << "Err: Cannot delete!" << endl;
    return d;
}

template <class T>
void arr<T>::swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
int arr<T>::search(T x){
    for(int i = 0; i < length; i++){
        if(A[i] == x){ 
            if(x != 0){
                arr::swap(A[i], A[i-1]);
                return i-1;
            }else
                return i;
        }
    }
    return -1;
}

template <class T>
int arr<T>::binarySearch(T x, int l, int h){
    int mid = (l+h)/2;
    if(l>h) return -1;
    else if(A[mid] == x) return mid;
    else{
        if(A[mid] > x) mid = arr::binarySearch(x, l, mid-1);
        else mid = arr::binarySearch(x, mid+1, h);
        return mid;
    }
}

template <class T>
int arr<T>::bs(T x){
    return binarySearch(x, 0, length);
}

int main(){
    arr<int> Arr(10);
    Arr.create();
    Arr.display();
    cout << Arr.bs(23) << endl;
    return 0;
}
