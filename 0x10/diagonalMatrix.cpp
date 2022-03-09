#include <iostream>
#include "matrix.h"

using namespace std;

template <class T>
class diaM:public matrix<T>{
    private:
        int d;
    public:
        diaM(int size, int d);
        void set(int i, int j, T val);
        T get(int i, int j);
        void display();
};

template <class T>
diaM<T>::diaM(int size, int d):matrix<T>(size){
    this->d = d;
}

template <class T>
void diaM<T>::set(int i, int j, T val){
    if(i == j){
        matrix<T>::set(i-1, val);
    }
    else
        cout << "cannot set value!\n" << endl;
}

template <class T>
T diaM<T>::get(int i, int j){
    if(i == j)
        matrix<T>::get(i);

}

template <class T>
void diaM<T>::display(){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(i == j)
                cout << matrix<T>::get(i) << " ";
            else
                cout << "0 " ;
        }
        cout << endl;
    }
}

int main(){
    diaM<int> M(10, 3);
    M.set(1,1, 1);
    M.set(2,2, 2);
    M.set(3,3, 3);
    M.display();
}
