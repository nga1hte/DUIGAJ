#include <iostream>
using namespace std;

class node{
    public:
        int col;
        int data;
        node *next;
};

class sparseM{
    public:
        int row;
        node **M;
        sparseM(int r){
            row = r;
            M = new node*[r]();
            for(int i = 0; i < r; i++)
                M[i] = NULL;
        }

        void create(int num);
        void display();
        void displayM();
};

int main(){
    sparseM M(3);
    M.create(4);
    cout << "List" << endl;
    M.display();
    cout << "Matrix" << endl;
    M.displayM();
}

void sparseM::create(int num){
    int data, r, c;
    cout << "r c d" << endl;

    for(int i = 0; i < num; i++){
        cin >> r;
        cin >> c; 
        cin >> data;
        node *temp = M[r];
        node *val = new node();
        val->data = data;
        val->col = c;
        val->next = NULL;
        if(temp != NULL){
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = val;
        }else{
            M[r] = val;
        }
    }

}

void sparseM::display(){
    node *p;
    for(int i = 0; i < row; i++){
        p = M[i];
        while(p != NULL){
            cout << i << " "  << p->col << " "  << p->data << " -> ";
            if(p->next == NULL)
                cout << "NULL";
            p = p->next;
        }
        cout << endl;
    }
}

void sparseM::displayM(){
    node *p;
    for(int i = 0; i < row; i++){
        p = M[i];
        for(int j = 0; j < row; j++){
            if( p && p->col == j){
                cout << p->data << " ";
                p = p->next;
            }else
                cout << "0 ";
        }
        cout << endl;

    }
    
}
