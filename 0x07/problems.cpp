#include "arrayADT.h"

template <class T>
int missing(arr<T> a){
    int sum = 0;
    int l = a.getl();
    int n = a.gete(l-1);
    int missing;
    for(int i = 0; i < l; i++){
        sum += a.gete(i);
    }
    missing = n*(n+1)/2 - sum;
    return missing;
}

template <class T>
void missing2(arr<T> a){
    int l = a.getl();
    int diff = a.gete(0) - 0;
    for(int i = 0; i < l; i++){
        if(a.gete(i) - i != diff){
            while(diff < a.gete(i) - i){
                cout << "Missing: " << i + diff << endl;
                diff++;
            }
            diff = a.gete(i) - i;
        }
    }
}

template <class T>
void missing3(arr<T> a){
    arr<int> table(50);
    table.setl(a.max()+1);
    for(int i = 0; i < table.getl(); i++){
        table.set(i, 0);
    }
    for(int i = 0; i < a.getl(); i++){
        table.set(a.gete(i), 1);
    }
    for(int i = a.min(); i < table.getl(); i++){
        if(table.gete(i) == 0){
            cout << "Missing: " << i << endl;
        }
    }

}

int main(){
    arr<int>a(10);
    a.create();
    a.display();
    missing3(a);
}
