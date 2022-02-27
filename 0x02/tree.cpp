#include <iostream>
using namespace std;


void series(int n){
    if(n > 0){
        cout << n << endl;
        series(n-1);
        series(n-1);
    }
}

int main(){
    series(3);
}
