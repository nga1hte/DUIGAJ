#include<iostream>
#include<queue>
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

void bfs(int v, int arr[][8], int n){
    int visited[8] = {0};
    queue<int> q;
    visited[v] = 1;
    q.push(v);
    int val;
    while(!q.empty()){
        val = q.front();
        q.pop();
        cout << val << " ";
        for(int i = 1; i < n; i++){
            if (arr[val][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
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
    bfs(1, arr, size);
    cout << "vertex 4: " << endl;
    bfs(4, arr, size);
    cout << "vertex 5: " << endl;
    bfs(6, arr, size);

    return 0;
}
