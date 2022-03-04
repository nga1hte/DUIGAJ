#include "arrayADT.h"

template <class T>
class setOps : public arr<T>{
    public:
        setOps(int n);
        void Union(setOps a, setOps b);
};


template <class T>
setOps<T>::setOps(int n):arr<T>(n){};


template <class T>
void setOps<T>::Union(setOps a, setOps b){
    int i = 0, j = 0, k = 0;
    int l = a.getl(), m = b.getl();
    while(i < l && j < m){
        if(a.gete(i) < b.gete(j)){
            arr<T>::set(k, a.gete(i));
            i++;
            k++;
        }else if(b.gete(j) < a.gete(i)){
            arr<T>::set(k, b.gete(j));
            j++;
            k++;
        }else{
            arr<T>::set(k, b.gete(j));
            i++;
            j++;
            k++;
        }
    }
    for(;i<l;i++){
        arr<T>::set(k, a.gete(i));
        k++;
    }
    for(;j<m;j++){
        arr<T>::set(k, b.gete(j));
        k++;
    }
    arr<T>::setl(k);
}



int main(){
    setOps<int> arr1(10);
    setOps<int> arr2(10);
    setOps<int> arr3(10);
    arr1.create();
    arr2.create();
    arr3.Union(arr1, arr2);
    arr3.display();
    return 0;
}
