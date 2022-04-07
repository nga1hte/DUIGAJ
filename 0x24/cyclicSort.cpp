#include <iostream>
using namespace std;

void swap(int arr[], int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void cyclicSort(int arr[], int size){
    int i = 0;
    int correct;
    while(i < size){
        correct = arr[i]-1;
        if(arr[i] != arr[correct]){
            swap(arr, i, correct);
        }else{
            i++;
        }
    }
}

void cyclicSort2(int arr[], int size){
    int i = 0;
    int correct;
    while(i < size){
        correct = arr[i] - 1;
        if(i != correct){
            swap(arr, i, correct);
        }else{
            i++;
        }
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {5, 1, 3, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    cyclicSort2(arr, size);
    display(arr, size);
    return 0;
}
