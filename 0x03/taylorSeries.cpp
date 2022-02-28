#include <iostream>
using namespace std;

double e(int x, int n){
    static double p = 1, f = 1;
    double r;
    if(n == 0)
        return 1;
    else{
        r = e(x, n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }

}

double e2(double x, int n){ //horner
    double r = 1;
    while(n > 0){
        r = 1 + x*r/n;
        n--;
    }
    return r;
}

double e4(int x, int n){
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + x*s/n;
    return e4(x, n-1);
}

int main(){
    cout << e(4, 5) << endl;
    cout << e2(4, 5) << endl;
    cout << e4(4, 5) << endl;
}
