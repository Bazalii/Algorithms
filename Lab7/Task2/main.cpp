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

int Height(Node *p)
{
    if (p) return p->height;
    else return 0;
}

int Diff(Node *p){
    return Height(p->right) - Height(p->left);
}

void Check_height(Node *p){
    char hleft= Height(p->left);
    char hright= Height(p->right);
    p->height=(hleft>hright ? hleft : hright)+1;
}

Node* RightRotation(Node *x)
{
    Node *y=x->left;
    x->left=y->right;
    y->right=x;
    Check_height(x);
    Check_height(y);
    return y;
}

Node *LeftRotation(Node *y)
{
    Node *x=y->right;
    y->right=x->left;
    x->left=y;
    Check_height(y);
    Check_height(x);
    return x;
}

Node *Balance(Node *x)
{
    Check_height(x);
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

Node *Insert(Node *x, int k)
{
    if (!x){
        return new Node(k);
    }
    if (k<x->key) x->left=Insert(x->left, k);
    else x->right=Insert(x->right, k);
    Check_height(x);
    return x;
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
    ifstream fin("rotation.in");
    ofstream fout("rotation.out");
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
    Avl_Tree = Balance(Avl_Tree);
    Avl_Tree->Fix_Size();
    fout << n <<endl;
    Print(Avl_Tree, 1, fout);
}

