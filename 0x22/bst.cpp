#include <iostream>
#include <stack>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
};

class bst{
    public:
    node *root;
    bst(){
        root = NULL;
    }

    void itInsert(int data);
    node* insert(int data){return insert(root, data);}
    node* insert(node *p, int data);
    void inOrder(){return inOrder(root);}
    void inOrder(node *p);
    void preOrder(){return preOrder(root);}
    void preOrder(node *p);
    node *deleteN(int key){return deleteN(root, key);}
    node *deleteN(node *p, int key);
    node *max(){return max(root);}
    node *min(){return min(root);}
    node *max(node *p);
    node *min(node *p);
    int height(node *p);
    void createBst(int pre[], int n);
};

int bst::height(node *p){
    int x, y;
    if(p == NULL) return 0;
    x = height(p->left);
    y = height(p->right);

    return (x > y) ? x + 1 : y + 1;
}

void bst::inOrder(node *p){
    if(p != NULL){
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

void bst::preOrder(node *p){
    if(p != NULL){
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void bst::itInsert(int data){
    node *t, *p;
    node *n = new node();
    n->data = data;
    n->left = n->right = NULL;
    p = root;
    t = p;
    if(p == NULL){
        root = n; 
        return;
    }

    while(p != NULL){
        t = p;
        if(data == p->data)
            return;
        else if(p->data > data)
            p = p->left;
        else 
            p = p->right;
    }
    if(t->data > data)
        t->left = n;
    else
        t->right = n;
}

node *bst::insert(node *p, int data){
    if(p == NULL){
        node *n = new node();
        n->data = data;
        n->left = n->right = NULL;
        return n;
    }else if(p->data == data){
        return p;
    }else if(p->data > data)
        p->left = insert(p->left, data);
    else 
        p->right = insert(p->right, data);
    return p;
}

node *bst::max(node *p){
    if(p == NULL){
        return NULL;
    }else{
        while(p->right != NULL){
            p = p->right;
        }
        return p;
    }
}

node *bst::min(node *p){
    if(p == NULL){
        return NULL;
    }else{
        while(p->left != NULL){
            p = p->left;
        }
        return p;
    }
}

node *bst::deleteN(node *p, int key){
    node *q;
    if(p == NULL)
        return NULL;
    if(p->left == NULL && p->right == NULL && p->data == key) {
        if(p == NULL)
            root = NULL;
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->left = deleteN(p->left, key);
    else if(key > p->data)
        p->right = deleteN(p->right, key);
    else{
        if(height(p->left) > height(p->right)){
            q = max(p->left);
            p->data = q->data;
            p->left =  deleteN(p->left, q->data);
        }else{
            q = min(p->right);
            p->data = q->data;
            p->right =  deleteN(p->right, q->data);
        }
    }
    return p;
}

void bst::createBst(int pre[], int n){
    stack <node*>s;
    node *t, *p;
    int i = 0;
    root = new node();
    root->data = pre[i++];
    root->left = root->right = NULL;
    p = root;
    while(i < n){
        if(pre[i] < p->data){
            t = new node();
            t->data = pre[i++];
            t->left = t->right = NULL;
            p->left = t;
            s.push(p);
            p = t;
        }else{
            if(pre[i] > p->data && pre[i] < s.empty() ? 32767 : s.top()->data){
                t = new node();
                t->data = pre[i++];
                t->left = t->right = NULL;
                p->right = t;
                p = t;
            }else{
                p = s.top();
                s.pop();
            }
        }
        
    }
}

int main(){
    bst a;
    a.itInsert(5);
    a.itInsert(3);
    a.itInsert(7);
    a.itInsert(2);
    a.itInsert(4);
    a.itInsert(6);
    a.itInsert(8);
    a.inOrder();
    cout << endl;
    bst b;
    b.root = b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(2);
    b.insert(4);
    b.insert(6);
    b.insert(8);
    b.inOrder();
    cout << endl;
    cout << b.max()->data << " " << b.min()->data;
    cout << endl;
    b.deleteN(8);
    b.inOrder();
    cout << endl;
    int pre[] = {30,20,10,15,25,40,50,45};
    bst c;
    c.createBst(pre, 8);
    c.inOrder();
    cout << endl;
    c.preOrder();
    cout << endl;

}
