#include <iostream>
#include "../0x10/matrix.h"
using namespace std;

template <class T>
class upperM:public matrix<T>{
    private:
        int d;
    public:
        upperM(int size, int d);
        void set(int i, int j, T val);
        T get(int i, int j);
        void display();
};

template <class T>
upperM<T>::upperM(int size, int d):matrix<T>(size){
    this->d = d;
};

template <class T>
void upperM<T>::set(int i, int j, T val){
    if(i <= j){
        int index = ((i-1)*d - (((i-2)*(i-1))/2))+(j-i);
        matrix<T>::set(index, val);
    }
}

template <class T>
T upperM<T>::get(int i, int j){
    if(i <= j){
        int index = ((i-1)*d - (((i-2)*(i-1))/2)) + (j-i);
        return matrix<T>::get(index);
    }else 
        return -1;
}

template <class T>
void upperM<T>::display(){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(i <= j){
                cout << get(i+1, j+1) << " ";
            }else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    upperM<int> M(10, 3);
    M.set(1,1, 1);
    M.set(1,2, 2);
    M.set(1,3, 3);
    M.set(2,2, 4);
    M.set(2,3, 5);
    M.set(3,3, 6);
    M.display();

}
