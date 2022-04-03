#include <iostream>
using namespace std;

class node{
    public:
        node *left;
        node *right;
        int data;
        int height;
};

class avl{
    public:
    node *root;
    avl(){root = NULL;}
    node *insert(int data){return insert(root,data);}
    node *insert(node *p, int data);
    int height(node *p);
    int balanceF(node *p);
    node *llRotation(node *p);
    node *lrRotation(node *p);
    node *rrRotation(node *p);
    node *rlRotation(node *p);
    void preOrder(){preOrder(root);};
    void preOrder(node *p);
    void inOrder(){inOrder(root);};
    void inOrder(node *p);
    node *deleteN(int key){return deleteN(root, key);}
    node *deleteN(node *p, int key);
    node *min(){return min(root);} 
    node *min(node *p); 
    node *max(){return max(root);} 
    node *max(node *p); 
};

int main(){
    avl a;
    a.root = a.insert(5);
    a.insert(9);
    a.insert(7);
    a.insert(10);
    a.insert(6);
    a.insert(8);
    a.preOrder();
    cout << endl;
    a.inOrder();
    cout << endl;
    a.deleteN(6);
    a.preOrder();
    cout << endl;
    a.deleteN(5);
    a.preOrder();
    cout << endl;
    a.deleteN(10);
    a.preOrder();
    cout << endl;
}

void avl::preOrder(node *p){
    if(p != NULL){
        cout << p->data << " "; 
        preOrder(p->left);
        preOrder(p->right);
    }
}

void avl::inOrder(node *p){
    if(p != NULL){
        inOrder(p->left);
        cout << p->data << " "; 
        inOrder(p->right);
    }
}

int avl::height(node *p){
    int x, y;

    x = p && p->left ? p->left->height : 0;
    y = p && p->right ? p->right->height : 0;

    return x > y ? x+1 : y+1;
}

int avl::balanceF(node *p){
    int x, y;

    x = p && p->left ? p->left->height : 0;
    y = p && p->right ? p->right->height : 0;
    return x-y;
}


node *avl::insert(node *p, int data){
    node *t = NULL;
    if(p == NULL){
        t = new node();
        t->data = data;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }

    if(data < p->data)
        p->left = insert(p->left, data);
    else if(data > p->data)
        p->right = insert(p->right, data);

    p->height = height(p);

    if(balanceF(p) == 2 && balanceF(p->left) == 1)
        return llRotation(p); 
    else if(balanceF(p) == 2 && balanceF(p->left) == -1)
        return lrRotation(p);
    else if(balanceF(p) == -2 && balanceF(p->right) == -1)
        return rrRotation(p);
    else if(balanceF(p) == -2 && balanceF(p->right) == 1)
        return rlRotation(p);
    return p;
}

node *avl::llRotation(node *p){
    node *pl = p->left;
    node *plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = height(p);
    pl->height = height(pl);
    if(root == p)
        root = pl;
    return pl;
}

node *avl::lrRotation(node *p){
    node *pl = p->left;
    node *plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->right = p;
    plr->left = pl;
    plr->height = height(plr);
    p->height = height(p);
    pl->height = height(pl);

    if(root == p)
        root = plr;
    return plr;
}

node *avl::rrRotation(node *p){
    node *pr = p->right;
    node *prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = height(p);
    pr->height = height(pr);
    if(root == p)
        root = pr;
    return pr;
}

node *avl::rlRotation(node *p){
    node *pr = p->right;
    node *prl = pr->left;
    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;
    p->height = height(p);
    pr->height = height(pr);
    prl->height = height(prl);
    if(root == p)
        root = prl;
    return prl;
}

node *avl::deleteN(node *p, int key){
    if(p == NULL)
        return NULL; 

    if(p->left == NULL && p->right == NULL && p->data == key){
        if(p == NULL)
            root = NULL;
        delete p; 
        return NULL;
    }

    if(key < p->data){
        p->left = deleteN(p->left, key);
    }else if(key > p->data){
        p->right = deleteN(p->right, key);
    }else{
        if(height(p->left) > height(p->right)){
            node *t = max(p->left);
            p->data = t->data;
            p->left = deleteN(p->left, t->data);
        }else{
            node *t = min(p->left);
            p->data = t->data;
            p->right = deleteN(p->right, t->data);
        }
    }
    p->height = height(p);
    if(balanceF(p) == 2 && balanceF(p->left) == 1)
        return llRotation(p);
    else if(balanceF(p) == 2 && balanceF(p->left) == -1)
        return lrRotation(p);
    else if(balanceF(p) == 2 && balanceF(p->left) == 0)
        return llRotation(p);
    if(balanceF(p) == -2 && balanceF(p->left) == -1)
        return rrRotation(p);
    else if(balanceF(p) == -2 && balanceF(p->left) == 1)
        return rlRotation(p);
    else if(balanceF(p) == -2 && balanceF(p->left) == 0)
        return rrRotation(p);

    return p;
}

node *avl::min(node *p){
    if(p->left == NULL)
        return p;
    return min(p->left);
}

node *avl::max(node *p){
    if(p->right == NULL)
        return p;
    return max(p->right);
}
