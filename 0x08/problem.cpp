#include "../0x07/arrayADT.h"

template <class T>
void findDuplicates(arr<T> a){
    int l = a.getl();
    T lastDup = 0;
    for(int i = 0; i < l-1; i++){
        if(a.gete(i) == a.gete(i+1)){
            if(lastDup != a.gete(i)){
                cout << "Dup: " << a.gete(i) << endl;
                lastDup = a.gete(i);
            }
        }
    }
}

template <class T>
void findDuplicate2(arr<T> a){
    int l = a.max();
    arr<int> table(50);
    table.setl(l);
    for(int i = 0; i < l; i++)
        table.set(i, 0);
    for(int i = 0; i < a.getl(); i++){
        int key = a.gete(i);
        table.set(key, table.gete(key)+1);
    }
    for(int i = a.min(); i < a.max()+1; i++){
        if(table.gete(i) > 1){
            cout << "Dup: " << i << "  x " << table.gete(i) << " times"  << endl;
        }
    }

}



int main(){
    arr<int> a(10);
    a.create();
    a.display();
    findDuplicate2(a);
}
