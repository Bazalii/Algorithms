#include <iostream>
#include <fstream>

using namespace std;

bool  Check(int** Tree, int i, int high, int low, bool flag) {
    int high_arr = high, low_arr = low;
    if (Tree[i][1] != 0) {
        high_arr = Tree[i][0];
        if (!Check(Tree, Tree[i][1] - 1, high_arr, low, flag))
            flag = false;
        if (high <= low)
            return (Tree[i][0] < high && flag) ? true : false;
    }
    if (Tree[i][2] != 0) {
        low_arr = Tree[i][0];
        if (!Check(Tree, Tree[i][2] - 1, high, low_arr, flag))
            flag = false;
        if (high <= low)
            return (Tree[i][0] < high && flag) ? true : false;
    }
    return (Tree[i][0] < high && Tree[i][0] > low && flag) ? true : false;
}

int main() {
    ifstream fin("check.in");
    ofstream fout("check.out");
    int n;
    fin >> n;
    int** Tree = new int* [n];
    for (int i = 0; i < n; i++) {
        Tree[i] = new int[3];
        fin >> Tree[i][0] >> Tree[i][1] >> Tree[i][2];
    }
    if (n == 0)
        fout << "YES";
    else {
        Check(Tree, 0, 10000000010, -10000000010, true) ? fout << "YES" : fout << "NO";
    }
    fin.close();
    fout.close();
    return 0;
}