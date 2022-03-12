#include <iostream>
using namespace std;

typedef struct elem{
    int x;
    int y;
    int v;
}elem;

//3 column representation
class sparseM{
    public:
        int r;
        int c;
        int val;
        elem *m;

        sparseM(int r, int c, int n);
        void display();
        void create();
        void add(sparseM a, sparseM b);
        void displayM();
};

sparseM::sparseM(int r, int c, int n){
    val = n;
    m = new elem[val];
    this->r = r;
    this->c = c;
}

void sparseM::create(){
    for(int i = 0; i < val; i++){
        cout << "m: ";
        cin >> m[i].x;
        cout << "n: ";
        cin >> m[i].y;
        cout << "v: ";
        cin >> m[i].v;
    }
}

void sparseM::add(sparseM a, sparseM b){
    int i = 0, j = 0, k = 0;
    while(i < a.val && j < b.val){
        if(a.m[i].x < b.m[j].x){
            m[k] = a.m[i];
            i++;
            k++;
        }else if(a.m[i].x > b.m[j].x){
            m[k] = b.m[j];
            j++;
            k++;
        }else if(a.m[i].y < b.m[j].y){
            m[k] = a.m[i];
            i++;
            k++;
        }else if(a.m[i].y > b.m[j].y){
            m[k] = b.m[j];
            j++;
            k++;
        }else{
            m[k].v = a.m[i].v + b.m[j].v;
            m[k].x = a.m[i].x;
            m[k].y = a.m[i].y;
            i++;
            j++;
            k++;
        }
    }
    for(; i<a.val; i++) m[k++] = a.m[i];
    for(; j<b.val; j++) m[k++] = b.m[j];
    val = k;
}

void sparseM::display(){
    cout << "m:"<< r <<"\tn:" << c << "\tv:" << val << endl;
    for(int i = 0; i < val; i++){
        cout << " " << m[i].x << "\t " << m[i].y << "\t " << m[i].v << endl;
    }
}

void sparseM::displayM(){
    int k = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(m[k].x == i && m[k].y == j)
                cout << m[k++].v << " ";
            else
                cout << "0 " ;
        }
        cout << endl;
    }
}

int main(){
    sparseM a(3,3,3);
    a.create();
    a.display();
    sparseM b(3,3,6);
    b.create();
    b.display();
    sparseM c(a.r, a.c, a.val+b.val);
    c.add(a, b);
    c.display();
    c.displayM();

}

