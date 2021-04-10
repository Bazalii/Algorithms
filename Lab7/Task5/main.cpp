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

int Diff(Node *p){
    if (p == NULL) return 0;
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
    if (Diff(x) == 2){
        if (Diff(x->right) < 0) x->right=RightRotation(x->right);
        return LeftRotation(x);
    }
    if (Diff(x) == -2)
    {
        if (Diff(x->left) > 0) x->left=LeftRotation(x->left);
        return RightRotation(x);
    }
    return x;
}

Node *Insert(Node *x, int k){
    if (!x){
        return new Node(k);
    }
    if (k<x->key) x->left=Insert(x->left, k);
    else if (k>x->key) x->right=Insert(x->right, k);
    else return x;
    return Balance(x);
}

Node *SearchMax(Node *x){
    if (x->right) return SearchMax(x->right);
    else return x;
}

Node *DeleteMax(Node *x){
    if (x->right == NULL) return x->left;
    x->right= DeleteMax(x->right);
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
        if (!y) return z;
        Node* max = SearchMax(y);
        max->left= DeleteMax(y);
        max->right=z;
        return Balance(max);
    }
    return Balance(x);
}

bool Exists(Node *x, int value){
    if (!x) return 0;
    if (value<x->key) return Exists(x->left, value);
    else if (value>x->key) return Exists(x->right, value);
    else return 1;
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
    ifstream fin("avlset.in");
    ofstream fout("avlset.out");
    Node *Avl_Tree = NULL;
    int n, value;
    string Command;
    fin >> n;
    while (fin >> Command){
        if (Command == "A"){
            fin >> value;
            Avl_Tree = Insert(Avl_Tree, value);
            fout << Diff(Avl_Tree) << endl;
        }
        else if (Command == "D"){
            fin >> value;
            Avl_Tree = Delete(Avl_Tree, value);
            fout << Diff(Avl_Tree) << endl;
        }
        else if (Command == "C"){
            fin >> value;
            if(Exists(Avl_Tree, value)) fout << "Y" << endl;
            else fout << "N" << endl;
        }
    }
}

