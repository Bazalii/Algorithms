#include <iostream>
#include <fstream>

using namespace std;

int Height(int **Tree, int* Max_Length, int i, int left, int right) {
    if (Tree[i][1] != 0){
        left = Height(Tree, Max_Length, Tree[i][1] - 1, left, right);
        Max_Length[i] = right - left;
    }
    else
        left = 0;
    if (Tree[i][2] != 0){
        right = Height(Tree, Max_Length, Tree[i][2] - 1, left, right);
        Max_Length[i] = right - left;
    }
    else
        right = 0;
    return (right > left) ? 1 + right : 1 + left;
}

int Get_The_Tree_Balanced(int** Tree,int *Max_Length, int i, int left, int right) {
    if  (Max_Length[i] != -100)
        return Max_Length[i];
    if (Tree[i][1] != 0)
        left = Height(Tree, Max_Length,Tree[i][1] - 1, left, right);
    else
        left = 0;
    if (Tree[i][2] != 0)
        right = Height(Tree, Max_Length,Tree[i][2] - 1, left, right);
    else
        right = 0;
    return right - left;
}


int main() {
    ifstream fin("balance.in");
    ofstream fout("balance.out");
    int n, left = 0, right = 0;
    fin >> n;
    int** Tree = new int* [n];
    int* Max_Length = new int [n];
    for (int i = 0; i < n; i++) {
        Tree[i] = new int[3];
        fin >> Tree[i][0] >> Tree[i][1] >> Tree[i][2];
        Max_Length[i] = -100;
    }
    if (n == 0)
        fout << 0;
    else {
        for (int i = 0; i < n; i++) {
            fout << Get_The_Tree_Balanced(Tree,Max_Length, i, left, right) << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}