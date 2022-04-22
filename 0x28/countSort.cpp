#include <iostream>
using namespace std;

int largest(int arr[], int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countSort(int arr[], int size){
    int s = largest(arr, size);
    int temp[s+1] = {0}; 
    for(int i = 0; i < size; i++)
       temp[arr[i]] = temp[arr[i]] + 1;
    for(int j = 0, k = 0; j <= s;){
        if(temp[j] > 0){
            arr[k++] = j;
            temp[j] = temp[j] - 1;
        }else
            j++;
    }

}

int main(){
    int arr[] = {5,7,1,1,2,6,9,3 };
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    countSort(arr, size);
    display(arr, size);
}
