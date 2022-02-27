#include <iostream>
using namespace std;

int sumOfFirstN(int n){
    if(n == 0)
        return 0;
    else{
        
        return n + sumOfFirstN(n-1);
    }
}

int sumOfFN(int n){
    return n*(n+1)/2;
}

int main(){
    cout << sumOfFN(5) << endl;
}
