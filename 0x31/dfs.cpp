#include<iostream>
#include<stack>
using namespace std;

void display(int arr[][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i == 0)
                cout << j << " "; 
            else if(j == 0)
               cout << i << " ";
            else
               cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//recursive method
void dfs(int v, int arr[][8], int n){
    static int visited[8] = {0};
    if(visited[v] == 0){
        cout << v << " ";
        visited[v] = 1;
        for(int i = 1; i < n; i++){
            if(arr[v][i] == 1)
                dfs(i, arr, n);
        }
    }
}

//iterative stack method
void idfs(int v, int arr[][8], int n){
    int visited[8] = {0};
    stack<int> s;
    visited[v] = 1;
    s.push(v);
    cout << v << " ";
    int i = 0;
    while(!s.empty()){
        while(i < n){
            if(arr[v][i] == 1 && visited[i] ==  0){
                s.push(v);
                v = i;
                cout << v << " ";
                visited[v] = 1;
                i = -1;
            }
            i++;
        }
        i = 0;
        v = s.top();
        s.pop();
    }
}

//void simpler dfs from back of stack
void sdfs(int v, int arr[][8], int n){
    int visited[8] {0};
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        v = s.top();
        s.pop();
        if(visited[v] != 1){
            cout << v << " ";
            visited[v] = 1;
            for(int i = n - 1; i >= 0; i--){
                if(arr[v][i] == 1 && visited[i] == 0)
                s.push(i);
            }
        }
        
    }
}

int main(){
    int arr[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0},
        {0,1,0,1,0,0,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,0,1,0,1,0,0},
        {0,0,0,1,1,0,1,1},
        {0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0},
    };
    display(arr);
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << "vertex 1: " << endl;
    sdfs(5, arr, size);
    cout << endl;

    return 0;
}
