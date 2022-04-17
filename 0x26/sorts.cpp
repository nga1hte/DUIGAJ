#include <iostream>
using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void display(int a[], int size){
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

//Adaptive: Does not resort sorted
//Stable: Does not change position of duplicates
//Time complexity: O(n2)
void bubbleSort(int a[], int size){
    int flag;
    for(int i = 0; i < size-1; i++){
        flag = 0;
        for(int j = 0; j < size-1-i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

//Adaptive: Does not resort sorted
//Stable: Does not change position of duplicates
//Time complexity: O(n2)
void insertionSort(int a[], int size){
    int j, val;
    for(int i = 1; i < size; i++){
        j = i-1;
        val = a[i];
        while(j >= 0 &&  val > a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }
}

//Time complexity: 0(n2)
void selectionSort(int a[], int size){
    int cmp;
    for(int i = 0; i < size - 1 ; i++){
        cmp = i;
        for(int j = i+1; j < size; j++){
            if(a[j] < a[cmp])
                cmp = j;
        }
        swap(a[cmp], a[i]);
    }
}


int main(){
    int arr[] = {6, 4, 3, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    selectionSort(arr, size);
    display(arr, size);
    return 0;
    
}
