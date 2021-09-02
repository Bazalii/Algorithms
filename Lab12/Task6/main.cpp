#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> tree, d;
int *weight;

void dfs(int vertex){
    d[vertex][0] = 0;
    d[vertex][1] = weight[vertex];
    for (int i : tree[vertex])
        dfs(i);
    for (int i : tree[vertex]){
        d[vertex][1] += d[i][0];
        d[vertex][0] += max(d[i][0], d[i][1]);
    }
}

int main() {
    int n, parent, root;
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");
    fin >> n;
    tree.resize(n, vector<int>());
    d.resize(n, vector<int>(2));
    weight = new int[n];
    for (int k = 0; k < n; ++k) {
        fin >> parent >> weight[k];
        if (parent != 0)
            tree[parent - 1].push_back(k);
        else
            root = k;
    }
    dfs(root);
    fout << max(d[root][0], d[root][1]);
    return 0;
}