#include <iostream>
using namespace std;

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int size){
    int gap, i, j, temp;
    for(gap = size/2; gap >= 1; gap/=2){
        for(i = gap; i < size; i++){
            temp = arr[i];
            j = i - gap;
            while(j >= 0 && arr[j] > temp){
                arr[j+gap] = arr[j];
                j = j - gap;
            }
            arr[j+gap] = temp;
        }
    }
}


int main(){
    int arr[] = {11, 13, 7, 12, 16, 0, 24, 5, 10, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    shellSort(arr, size);
    display(arr, size);
}
