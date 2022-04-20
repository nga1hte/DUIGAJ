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
    for(int l = 0; l <= h; l++)
        arr[l] = temp[l];
}

void msort(int arr[], int size){
    int p;
    for(p = 2; p <= size; p = p*2){
        for(int i = 0; i+p-1 < size; i = i+p){
            int l = i;
            int h = i + p - 1;
            int m = (l+h)/2;
            merge(arr, l, m, h);
        }
    }
    if(p/2 < size)
        merge(arr, 0, p/2-1, size-1);
}

int main(){
    int arr[] = {3,5,4,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    msort(arr, size);
    display(arr, size);

}

