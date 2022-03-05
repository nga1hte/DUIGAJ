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
        T gete(int x);
        int getl();
        void set(int x, T n);
        void reverse();
        void shift();
        void swap(T &a, T &b);
        void inSorted(T x);
        bool isSorted();
        void merge(arr a, arr b);
        void setl(int x);
        T max();
        T min();
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

template <class T>
void arr<T>::set(int x, T n){
        A[x] = n;
}

template <class T>
void arr<T>::reverse(){
    int i = 0, l = length - 1;
    while(i < l){
        swap(A[i], A[l]);
        i++;
        l--;
    }
}

template <class T>
void arr<T>::shift(){
    //left shift
    T temp = A[0];
    for(int i = 0; i < length - 1; i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

template <class T>
void arr<T>::inSorted(T x){
    int l = length - 1;
    while(A[l] > x){
        A[l+1] = A[l]; 
        l--;
    }
    A[l+1] = x;
    length++;
}

template <class T>
bool arr<T>::isSorted(){
    for(int i = 0; i < length-1; i++){
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

template <class T>
T arr<T>::gete(int x){
    return A[x];
}

template <class T>
int arr<T>::getl(){
    return length;
}

template <class T>
void arr<T>::setl(int x){
    length = x;
}

template <class T>
T arr<T>::max(){
    T max = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

template <class T>
T arr<T>::min(){
    T min = A[0];
    for(int i = 1; i < length; i++){
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

template <class T>
void arr<T>::merge(arr a, arr b){
    int i = a.getl(), j = b.getl(), k = 0;
    int l = 0, m = 0;
    
    while(l < i && m  < j){
        if(a.gete(l) < b.gete(m)){
            A[k++] = a.gete(l);
            l++;
        }else{
            A[k++] = b.gete(m);
            m++;
        }
    }
    for(;l < i; l++)
        A[k++] = a.gete(l);
    for(;m < j; m++){
        A[k++] = b.gete(m);
    }
    length = k;

}
