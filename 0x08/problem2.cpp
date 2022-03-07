#include "../0x07/arrayADT.h"

template <class T>
void sumK(arr<T> a, int k){
    arr<int> bitset(50);
    bitset.setl(a.max()+1);

    for(int i = 0; i < bitset.getl(); i++)
        bitset.set(i, 0);

    for(int i = 0; i < a.getl(); i++)
        bitset.set(a.gete(i), 1);

    for(int i = 0; i < a.getl(); i++){
        int val = k - a.gete(i);
        if(bitset.gete(val) == 1 && val != a.gete(i)){
           cout << a.gete(i) << " + " << val << " = " << k << endl;
           bitset.set(a.gete(i), 0);
        }
    }
}

template <class T>
void sumK2(arr<T> a, int k){
    arr<int> bitset(50);
    int val;
    bitset.setl(a.max()+1);

    for(int i = 0; i < bitset.getl(); i++)
        bitset.set(i, 0);

    for(int i = 0; i < a.getl(); i++){
        val = k - a.gete(i);
        if(bitset.gete(val) != 0){
            cout << a.gete(i) << " + " << val << " = " << k << endl;
            bitset.set(val, 1);
        }
        bitset.set(a.gete(i), 1);
    }

}
//for sorted array using loop only
template <class T>
void sumK3(arr<T> a, int k){
    int i = 0, j = a.getl() - 1;
    while(i < j){
        if(a.gete(i) + a.gete(j) == k){
            cout << a.gete(i) << " + " << a.gete(j) << " = " << k << endl;
            i++;
            j++;
        }else if(a.gete(i) + a.gete(j) > k){
            j--;
        }else{
            i++;
        }
    }
}


int main(){
    arr<int> a(20);
    a.create();
    a.display();
    sumK3(a, 10);
}
