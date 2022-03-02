#include <iostream>
using namespace std;

int fib(int n){
    if(n <= 1) return n;
    return fib(n-2) + fib(n-1);
}

int fib2(int n){
    if(n <= 1) return n;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int F[50];

int fib3(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    }else{
        if(F[n-2] == -1)
            F[n-2] = fib(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n-2] + F[n-1];
    }
    
}

int main(){

    for(int i = 0; i < 50; i++){
        F[i] = -1;
    }

    cout << fib(9) << endl;
    cout << fib2(9) << endl;
    cout << fib3(9) << endl;

}
