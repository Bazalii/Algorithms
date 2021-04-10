#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    ifstream fin ("game.in");
    ofstream fout ("game.out");
    int  n, m, a, b, position, current_vertex;
    vector<vector<int>> graph;
    vector<int> Color, Way;
    vector<bool> used, win;
    stack <int> main_stack;
    fin >> n >> m >> position;
    graph.resize(n, vector<int>());
    Color.resize(n);
    for (int i = 0; i < n; ++i) {
        Color[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    used.assign(n, false);
    win.assign(n, false);
    main_stack.push(position - 1);
    while (!main_stack.empty()){
        current_vertex = main_stack.top();
        if (!used[current_vertex]) {
            used[current_vertex] = true;
            for (int v : graph[current_vertex]) {
                if (!used[v])
                    main_stack.push(v);
            }
        }
        else{
            for (int v : graph[current_vertex]) {
                if (!win[v]) {
                    win[current_vertex] = true;
                }
            }
                main_stack.pop();
        }
    }
    if (win[position - 1]) {
        fout << "First player wins";
    } else {
        fout << "Second player wins";
    }

    return 0;
}
