#include <iostream>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

bool flag;

using namespace std;

struct Node{
    int key;
    int size;
    char height;
    Node *right;
    Node *left;
    int Fix_Size() {
    if (left != NULL) {
        size += left->Fix_Size();
    }
    if (right != NULL) {
        size += right->Fix_Size();
    }
    return size + 1;
}
    Node(int k) { key=k; height=1; left=right=0; size = 0; }
};

int height(Node *p){
    if (p) return p->height;
    else return 0;
}

int BF(Node *p){
    return height(p->right)-height(p->left);
}

void OverHeight(Node *p){
    char hleft=height(p->left);
    char hright=height(p->right);
    p->height=(hleft>hright ? hleft : hright)+1;
}

Node* RightRotation(Node *x){
    Node *y=x->left;
    x->left=y->right;
    y->right=x;
    OverHeight(x);
    OverHeight(y);
    return y;
}

Node *LeftRotation(Node *y){
    Node *x=y->right;
    y->right=x->left;
    x->left=y;
    OverHeight(y);
    OverHeight(x);
    return x;
}

Node *Balance(Node *x){
    OverHeight(x);
    if (BF(x)==2){
        if (BF(x->right)<0) x->right=RightRotation(x->right);
        return LeftRotation(x);
    }
    if (BF(x)==-2)
    {
        if (BF(x->left)>0) x->left=LeftRotation(x->left);
        return RightRotation(x);
    }
    return x;
}

Node *Insert(Node *x, int k){
    if (!x){
        return new Node(k);
    }
    if (k<x->key) x->left=Insert(x->left, k);
    else x->right=Insert(x->right, k);
    if (!flag){
       OverHeight(x);
       return x;
    }
    else
    {
        return Balance(x);
    }

}

Node *SearchMin(Node *x){
    if (x->left) return SearchMin(x->left);
    else return x;
}
Node *DeleteMin(Node *x){
    if (x->left==0) return x->right;
    x->left=DeleteMin(x->left);
    return Balance(x);
}

Node *Delete(Node *x, int k){
    if (!x) return 0;
    if (k<x->key) x->left=Delete(x->left, k);
    else if (k>x->key) x->right=Delete(x->right, k);
    else{
        Node *y=x->left;
        Node *z=x->right;
        delete x;
        if (!z) return y;
        Node* min=SearchMin(z);
        min->right=DeleteMin(z);
        min->left=y;
        return Balance(min);
    }
    return Balance(x);
}


int Print(Node *x, int pos, ofstream& fout) {
    fout << x->key << " ";
    pos++;
    if (x->left != 0) {
        fout << pos << " ";
    }
    else {
        fout << 0 << " ";
    }
    if (x->right != 0) {
        if (x->left != 0){
            fout << pos + x->left->size + 1 << "\n";
        }

        else
            fout << pos << "\n";
    }
    else {
        fout << 0 << "\n";
    }
    if (x->left != 0) {
        pos = Print(x->left, pos, fout);
    }
    if (x->right != 0) {
        pos = Print(x->right, pos, fout);
    }
    return pos;
}


int main() {
    ifstream fin("addition.in");
    ofstream fout("addition.out");
    Node *Avl_Tree = NULL;
    int n, value;
    fin >> n;
    int** Tree = new int* [n];
    flag = false;
    for (int i = 0; i < n; i++) {
        Tree[i] = new int[3];
        fin >> Tree[i][0] >> Tree[i][1] >> Tree[i][2];
        Avl_Tree = Insert(Avl_Tree, Tree[i][0]);
    }
    flag = true;
    while (fin >> value){
        Avl_Tree = Insert(Avl_Tree, value);
        n++;
    }
    Avl_Tree->Fix_Size();
    fout << n <<endl;
    Print(Avl_Tree, 1, fout);
}

