#include <iostream>
using namespace std;

typedef struct term{
    int exp;
    int coeff;
}term;

class poly{
    public:
        int n;
        term *p;
        poly(int n);
        void create();
        void display();
        int evaluate(int x);
        int exponent(int x, int n);
        void add(poly a, poly b);
};

poly::poly(int n){
    this->n = n;
    p = new term[n];
}

void poly::create(){
    cout << "coeff: [val] exp: [val]" << endl;
    for(int i = 0; i < n; i++){
        cin >> p[i].coeff;
        cin >> p[i].exp;
    }
}

void poly::display(){
    for(int i = 0; i < n; i++){
        cout << p[i].coeff << "x^" << p[i].exp << " ";

    }
    cout << endl;
}

/*poly::~poly(){
    delete []p;
}
*/

int poly::evaluate(int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += p[i].coeff*(exponent(x, p[i].exp));
    }
    return sum;
}

int poly::exponent(int x, int n){
    int exp = 1;
    for(int i = 0; i < n; i++){
        exp *= x;
    }
    return exp;
}

void poly::add(poly a, poly b){
    term *res = new term[a.n + b.n];
    int i = 0, j = 0, k = 0;
    while(i < a.n && j < b.n){
        if(a.p[i].exp == b.p[j].exp){
            res[k].exp = a.p[i].exp;
            res[k].coeff = a.p[i].coeff + b.p[j].coeff;
            i++;
            j++;
            k++;
        }else if(a.p[i].exp > b.p[j].exp){
            res[k] = a.p[i];
            i++;
            k++;
        }else{
            res[k] = b.p[j];
            j++;
            k++;
        }
    }
    for(; i < a.n; i++){
        res[k] = a.p[i];
        k++;
    }
    for(; j < b.n; j++){
        res[k] = b.p[j];
        k++;
    }
    n = k;
    p = res;
}



int main(){
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    poly p(n);
    p.create();
    p.display();
    cout << "Enter the number of terms: ";
    cin >> n;
    poly q(n);
    q.create();
    q.display();
    poly r(p.n+q.n);
    r.add(p, q);
    cout << "added: " << endl;
    r.display();
}
