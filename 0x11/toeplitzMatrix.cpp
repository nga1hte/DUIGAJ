#include <iostream>
#include "../0x10/matrix.h"
using namespace std;

template <class T>
class toeplitzM:public matrix<T>{
    private:
        int d;
    public:
        toeplitzM(int size, int d);
        void set(int i, int j, T val);
        T get(int i, int j);
        void display();
};

template <class T>
toeplitzM<T>::toeplitzM(int size, int d):matrix<T>(size){
    this->d = d;
};

template <class T>
void toeplitzM<T>::set(int i, int j, T val){
    int index = 0;
    if(i <= j){
        index = j-i;
    }else{
        index = d + i - j - 1;
    }
    matrix<T>::set(index, val);
}

template <class T>
T toeplitzM<T>::get(int i, int j){
    int index = 0;
    if(i <= j){
        index = j-i;
    }else 
        index = d + i - j - 1;
    return matrix<T>::get(index);
}

template <class T>
void toeplitzM<T>::display(){
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            if(i <= j){
                cout << get(i, j) << " ";
            }else
                cout << get(i, j) << " ";
        }
        cout << endl;
    }
}

int main(){
    toeplitzM<int> M(30, 5);
    M.set(1,1, 1);
    M.set(1,2, 2);
    M.set(1,3, 3);
    M.set(1,4, 4);
    M.set(1,5, 5);
    M.set(2,1, 6);
    M.set(3,1, 7);
    M.set(4,1, 8);
    M.set(5,1, 9);
    M.display();

}
