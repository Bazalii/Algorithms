#include <fstream>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

bool Search(Node *x, int k){
    if(x == NULL)
        return false;
    if(x->key == k)
        return true;
    if(k < x->key)
        return Search(x->left, k);
    else
        return Search(x->right, k);
}

Node *Insert(Node *&x, int a){
    if(x == NULL){
        x = new Node;
        x->key = a;
        x->left = x->right = NULL;
    }
    else if (x->key > a)
        Insert(x->left, a);
    else if (x->key < a)
        Insert(x->right, a);
    return x;
}

Node *Prev(Node *&root, int x){
    Node *current = root;
    Node *success = NULL;
    while(current != NULL){
        if(current->key < x){
            success = current;
            current = current->right;
        }
        else
            current = current->left;
    }
    return success;
}

Node *Next(Node *&root, int x){
    Node *current = root;
    Node *success = NULL;
    while(current != NULL){
        if(current->key > x){
            success = current;
            current = current->left;
        }
        else
            current = current->right;
    }
    return success;
}

Node *Min(Node *&x){
    if(x->left == NULL)
        return x;
    return Min(x->left);
}

Node *Max(Node *&x){
    if(x->right == NULL)
        return x;
    return Max(x->left);
}

Node *Delete(Node *&root, int i){
    if(root == NULL)
        return root;
    if(i < root->key)
        root->left = Delete(root->left, i);
    else if(i > root->key)
        root->right = Delete(root->right, i);
    else if(root->left != NULL && root->right != NULL){
        root->key = Min(root->right)->key;
        root->right = Delete(root->right, root->key);
    }
    else{
        if(root->left != NULL)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    Node *Tree = NULL;
    string command;
    while (fin >> command) {
        int value;
        fin >> value;
        if(command == "insert")
            Insert(Tree, value);
        if(command == "delete")
            Delete(Tree, value);
        if(command == "exists"){
            if(Search(Tree, value))
                fout << "true\n";
            else
                fout << "false\n";
        }
        if(command == "next"){
            Node *checker = Next(Tree, value);
            if(checker == NULL)
                fout << "none\n";
            else
                fout << checker->key << "\n";
        }
        if(command == "prev") {
            Node *checker = Prev(Tree, value);
            if (checker == NULL)
                fout << "none\n";
            else
                fout << checker->key << "\n";
        }
    }
}