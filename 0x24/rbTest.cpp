#include <iostream>
using namespace std;

class node{
    public:
    //red = 1, black = 0 
    int data;
    int color;
    node *left;
    node *right;
};

class rbTree{
    public:
    node *root;
    rbTree(){ root = NULL; }
    node *insert(int data){return insert(root, data);}
    node *insert(node *p, int data);
    void display(node *p);
    node *llRotate(node *p);
    node *rrRotate(node *p);
    node *lrRotate(node *p);
    node *rlRotate(node *p);
    int twoRed(node *p);
    node *inOrderPre(node *p);
    node *inOrderSucc(node *p);
    int height(node *p);
    node *deleteN(node *p, int key);
};

int main(){
    rbTree a;
    a.root = a.insert(5);
    a.insert(7);
    a.insert(9);
    a.insert(8);
    a.insert(10);
    a.insert(11);
    a.insert(4);
    a.insert(3);
    a.insert(12);
    a.insert(2);
    a.display(a.root);
    a.deleteN(a.root, 3);
    cout << "After Deletion" << endl;
    a.display(a.root);
    return 0;
}

node *rbTree::deleteN(node *p, int key){
    node *q;
    if(p == NULL)
        return NULL;
    if(p->left == NULL && p->right == NULL && p->data == key){
        if(root == p)
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
            q = inOrderPre(p->left);
            p->data = q->data;
            p->left = deleteN(p->left, q->data);
        }else{
            q = inOrderSucc(p->right);
            p->data = q->data;
            p->right = deleteN(p->right, q->data);
        }
    }
    
    return p;
}

int rbTree::height(node *p){
    int x, y;
    if(p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    if(x > y)
        return x + 1;
    else 
        return y + 1;
}

node *rbTree::inOrderPre(node *p){
    if(p->right == NULL)
        return p;
    return inOrderPre(p->right);
}

node *rbTree::inOrderSucc(node *p){
    if(p->left == NULL)
        return p;
    return inOrderSucc(p->left);
}

node *rbTree::insert(node *p, int data){
    node *temp;
    if(p == NULL){
        temp = new node();
        temp->left = NULL;
        temp->right = NULL;
        temp->data = data;
        if(root == p)
            temp->color = 0;
        else
            temp->color = 1;
        return temp;
    }
    if(data < p->data)
        p->left = insert(p->left, data);
    else if(data > p->data)
        p->right = insert(p->right, data);

    if(twoRed(p) > 0 && twoRed(p) <= 2){
        if(p->right == NULL || p->right->color == 0){
            if(twoRed(p) == 1)
                return llRotate(p);
            else if(twoRed(p) == 2)
                return lrRotate(p);
        }else if(p->right->color == 1){
            if(p != root)
                p->color = 1;
            p->left->color = 0;
            p->right->color = 0;
        }
    }else if(twoRed(p) >= 3 && twoRed(p) <= 4){
        if(p->left == NULL || p->left->color == 0){
            if(twoRed(p) == 3)
                return rrRotate(p);
            else if(twoRed(p) == 4)
                return rlRotate(p);
        }else if(p->left->color == 1){
            if(p != root)
                p->color = 1;
            p->left->color = 0;
            p->right->color = 0;
        }
        
    }

    //if(twoRed(p) == 1 && (p->right == NULL || p->right->color == 0))
    //    return llRotate(p);
    //else if(twoRed(p) == 2 && (p->right == NULL || p->right->color == 0))
    //    return lrRotate(p);
    //else if(twoRed(p) == 1 && p->right->color == 1){
    //    if(p != root)
    //        p->color = 1;
    //    p->left->color = 0;
    //    p->right->color = 0;
    //}
    return p;
}

void rbTree::display(node *p){
    if(p){
        cout << p->data << " " << "c: " << p->color << endl;
        display(p->left);
        display(p->right);
    }

}

node *rbTree::llRotate(node *p){
    node *ll = p->left;
    p->left = ll->right;
    ll->right = p;
    p->color = 1;
    ll->color = 0;
    if(root == p)
        root = ll;
    return ll;
}

node *rbTree::rrRotate(node *p){
    node *rr = p->right;
    p->right = rr->left;
    rr->left = p;
    p->color = 1;
    rr->color = 0;
    if(root == p)
        root = rr;
    return rr;
}

node *rbTree::lrRotate(node *p){
    node *ll = p->left;
    node *lr = ll->right;
    ll->right = lr->left;
    p->left = lr->right;
    lr->left = ll;
    lr->right = p;
    lr->color = 0;
    p->color = 1;
    if(root == p)
        root = lr;
    return lr;
}

node *rbTree::rlRotate(node *p){
    node *rr = p->right;
    node *rl = rr->left;
    rr->left = rl->right;
    p->right = rl->left;
    rl->right = rr;
    rl->left = p;
    rl->color = 0;
    p->color = 1;
    if(root == p)
        root = rl;
    return rl;
}

int rbTree::twoRed(node *p){
    if(p->left != NULL && p->left->color == 1){
        if(p->left->left != NULL && p->left->left->color == 1)
            return 1;
        else if(p->left->right != NULL && p->left->right->color == 1)
            return 2;
    }
    if(p->right != NULL && p->right->color == 1){
        if(p->right->right != NULL && p->right->right->color == 1)
            return 3;
        else if(p->right->left != NULL && p->right->left->color == 1)
            return 4;
    }
    return 0;
}
