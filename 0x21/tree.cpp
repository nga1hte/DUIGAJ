#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
};

class tree{
    public:
    node *root;
    void createTree();
    void preOrder(){preOrder(root);}
    void inOrder(){inOrder(root);}
    void postOrder(){postOrder(root);}
    void preOrder(node *p);
    void inOrder(node *p);
    void postOrder(node *p);
    void itPreOrder();
    void itInOrder();
    void itPostOrder();
    void levelOrder();
    int count(){return count(root);}
    int count(node *p);
    int height(){return height(root);}
    int height(node *p);
};

int main(){
    tree t;
    t.createTree();
    t.itPreOrder();
    cout << endl;
    t.itInOrder();
    cout << endl;
    t.itPostOrder();
    cout << endl;
    t.levelOrder();
    cout << endl;
    cout << "No. of nodes: " << t.count() << endl;
    cout << "Height: " << t.height() << endl;
}

void tree::createTree(){
    node *p, *t;
    int data;
    queue <node*>q;
    cout << "Enter the root node: ";
    cin >> data;
    t = new node();
    t->data = data;
    t->left = t->right = NULL;
    q.push(t);
    root = t;
    while(!q.empty()){
        p = q.front();
        q.pop();
        cout << "Enter left child: ";
        cin >> data;
        if(data != -1){
            t = new node();
            t->data = data;
            t->left = t->right = NULL;
            p->left = t;
            q.push(t);
        }
        cout << "Enter right child: ";
        cin >> data;
        if(data != -1){
            t = new node();
            t->data = data;
            t->left = t->right = NULL;
            p->right = t;
            q.push(t);
        }
    }
}

void tree::preOrder(node *p){
    if(p == NULL)
        return;
    cout << p->data << " ";
    preOrder(p->left);
    preOrder(p->right);
}

void tree::inOrder(node *p){
    if(p == NULL)
        return;
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
}

void tree::postOrder(node *p){
    if(p == NULL)
        return;
    postOrder(p->left);
    postOrder(p->right);
    cout << p->data  << " ";
}

void tree::itPreOrder(){
    stack <node*>s;
    node *p = root ;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            cout << p->data << " ";
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void tree::itInOrder(){
    stack <node*>s;
    node *p = root ;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            cout << p->data << " ";
            s.pop();
            p = p->right;
        }
    }
}

void tree::itPostOrder(){
    stack <long int>s;
    long int temp;
    node *p = root ;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            s.push((long int)p);
            p = p->left;
        }else{
            temp = s.top();
            s.pop();
            if(temp > 0){
                s.push(-temp);
                p = ((node *)temp)->right;
            }else{
                cout << ((node*)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
    }
}

void tree::levelOrder(){
    queue <node*>q;
    node *p = root;
    node *t;
    q.push(p);
    cout << p->data << " ";
    while(!q.empty()){
        t = q.front();
        q.pop();

        if(t->left != NULL){
            cout << t->left->data << " ";
            q.push(t->left);
        }

        if(t->right != NULL){
            cout << t->right->data << " ";
            q.push(t->right);
        }
    }
}

int tree::count(node *p){
    int x, y;
    if(p != NULL){
        x = count(p->left);
        y = count(p->right);
        return x + y + 1;
    }
    return 0;
}

int tree::height(node *p){
    int l = 0, r = 0;
    if(p != NULL){
        l = height(p->left);
        r = height(p->right);
        if(l > r)
            return l + 1;
        else
            return r +1;
    }
    return 0;
}

