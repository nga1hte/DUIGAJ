#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(){};
    node(int data);
};

node::node(int data){
    left = NULL;
    right = NULL;
    this->data = data;
}

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
    int leafNodes(){return leafNodes(root);}
    int leafNodes(node *p);
    node *generateTree(int *inorder, int *preorder, int inStart, int inEnd);
};

int searchInOrder(int inArray[], int inStart, int inEnd, int data){
    for(int i = inStart; i < inEnd; i++){
        if(inArray[i] == data){
            return i;
        }
    }
    return -1;
}

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
    cout << "leaf nodes: " << t.leafNodes() << endl;
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    node *g = t.generateTree(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    tree f;
    f.root = g;
    f.levelOrder();
    cout << endl;

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
        cout << "Enter left child of " << p->data << ": " << flush;
        cin >> data;
        if(data != -1){
            t = new node();
            t->data = data;
            t->left = t->right = NULL;
            p->left = t;
            q.push(t);
        }
        cout << "Enter left child of " << p->data << ": " << flush;
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
            return r + 1;
    }
    return -1;
}

int tree::leafNodes(node *p){
    int x, y;
    if(p != NULL){
        x = leafNodes(p->left);
        y = leafNodes(p->right);
        if(p->left == NULL ^ p->right == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

node* tree::generateTree(int *inorder, int *preorder, int inStart, int inEnd){
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;

    node *n = new node(preorder[preIndex++]);

    if(inStart == inEnd)
        return n;

    int splitIndex = searchInOrder(inorder, inStart, inEnd, n->data);

    n->left = generateTree(inorder, preorder, inStart, splitIndex-1);
    n->right = generateTree(inorder, preorder, splitIndex+1, inEnd);

    return n;
}
