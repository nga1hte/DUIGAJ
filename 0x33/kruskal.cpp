#include <iostream>
#define I 32473

using namespace std;

int edges[3][9] = {
                    {1, 1, 2, 2, 3, 4, 4, 5, 5},
                    {2, 6, 3, 7, 4, 5, 7, 6, 7},
                    {25, 5, 12, 10, 8, 16, 14, 20, 18}
                  };

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int included[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int t[2][6];

void Union(int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {
    int x = u;

    while (set[x] > 0){
        x = set[x];
    }

    return x;
}

void display(){
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int i = 0, j, k, n = 7, e = 9, min , u, v;
    
    while(i < n - 1){
        min = I;
        for(j = 0; j < e; j++) {
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        if(find(u) != find(v)){ 
            t[0][i] = u;
            t[1][i] = v;
            Union(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }

    display();
}

