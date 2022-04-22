#include <iostream>
using namespace std;

void display(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int m, int h){
    int i = l, j = m+1, k = l;
    int temp[h+1];
    while(i <= m && j <= h){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    for(;i <= m; i++)
       temp[k++] = arr[i];
    for(;j <= h; j++)
       temp[k++] = arr[j];
    for(int m = l; m <= h; m++)
        arr[m] = temp[m];
}

void msort(int arr[], int size){
    int p,l,h,m,i;
    for(p = 2; p <= size; p = p*2){
        for(i = 0; i+p-1 < size; i = i+p){
            l = i;
            h = i + p - 1;
            m = (l+h)/2;
            merge(arr, l, m, h);
        }
        if(size-i>p/2){
            l = i;
            h = i+p-1;
            m = (l+h)/2;
            merge(arr, l, m, size-1);
        }
    }
    if(p/2 < size)
       merge(arr, 0, p/2-1, size-1);
}

void mergeSort(int arr[], int l, int h){
    if(l < h){
        int mid = l+(h-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

int main(){
    int arr[] = {3,5,4,2,7,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    mergeSort(arr,0,size-1);
    display(arr, size);

}

