#include <iostream>
#include "matrix.h"
using namespace std;

template <class T>
class lowerM:public matrix<T>{
    private:
        int d;
    public:
        lowerM(int size, int d);
        void set(int i, int j, T val);
        T get(int i, int j);
        void display();
};

template <class T>
lowerM<T>::lowerM(int size, int d):matrix<T>(size){
    this->d = d;
};

template <class T>
void lowerM<T>::set(int i, int j, T val){
    if(i >= j){
        int index = ((i*(i-1))/2) + j-1;
        matrix<T>::set(index, val);
    }
}

template <class T>
T lowerM<T>::get(int i, int j){
    if(i >= j){
        int index = ((i*(i-1))/2) + j-1;
        return matrix<T>::get(index);
    }else 
        return -1;
}

template <class T>
void lowerM<T>::display(){
    int index;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(i >= j){
                cout << get(i+1, j+1) << " ";
            }else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    lowerM<int> M(10, 3);
    M.set(1,1, 1);
    M.set(2,1, 2);
    M.set(2,2, 3);
    M.set(3,1, 4);
    M.set(3,2, 5);
    M.set(3,3, 6);
    M.display();
}
