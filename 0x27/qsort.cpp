#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//using first element as pivot
int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l, j = h;
    while(i < j){
        while(i <= h && arr[i] <= pivot) i++;
        while(j >= 0 && arr[j] > pivot) j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

int partition2(int arr[], int l, int h){
    int mid = (l+h)/2;
    int pivot = arr[mid];
    int i = l, j = h;
    while(i <= j){
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void qsort(int arr[], int l, int h){
    if(l >= h)
        return;
    int pivot = partition2(arr, l, h);
    qsort(arr, l, pivot-1);
    qsort(arr, pivot, h);
}

int main(){
    int arr[] = {5, 5, 3, 2, 4, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    qsort(arr, 0, size-1);
    display(arr, size);
}
