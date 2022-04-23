#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

class llist{
    public:
        node* head;
        llist(){
            head = NULL;
        }
        void insert(int data){
            node *temp = new node();
            temp->data = data;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
            }else{
               node *p = head;
               while(p->next != NULL)
                   p = p->next;
               p->next = temp; 
            }
        }

        int deleteN(){
            if(head == NULL)
                return -1;
            int n = head->data;
            node *temp = head;
            head = head->next;
            delete temp;
            return n;

        }

        void display(){
            node *p = head;
            while(p != NULL){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
};

void display(int arr[], int size){
    for(int i = 0; i < size;  i++)
        cout << arr[i] << " ";
    cout << endl;
}

int largest(int arr[], int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

void binSort(int arr[], int size){
    int i, j;
    llist *bins;
    bins = new llist[10];

    for(i = 0; i < size; i++){
        bins[(arr[i])%10].insert(arr[i]);
    }

    i = 0, j = 0;
    while(i < 10){
        while(bins[i].head != NULL)
            arr[j++] = bins[i].deleteN();
        i++;
    }

    for(i = 0; i < size; i++){
        bins[((arr[i])/10)%10].insert(arr[i]);
    }

    i = 0, j = 0;
    while(i < 10){
        while(bins[i].head != NULL)
            arr[j++] = bins[i].deleteN();
        i++;
    }



    
}

int main(){
    int arr[] = {21, 4, 2, 5, 5, 1, 2, 3, 9 };
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr, size);
    binSort(arr, size);
    display(arr, size);
}
