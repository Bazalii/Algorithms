#pragma comment(linker, "/STACK:307108864")
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int>> graph;
vector<int> Color;
//vector<int> Array;
vector<int> Visited_vertexes;
vector<int> Not_visited_vertexes;
int checker = 0, n, m, checker_of_end = 0;
bool truth_checker = false;
ifstream fin ("bipartite.in");
ofstream fout ("bipartite.out");

bool in(int element, vector<int> list_to_check){
    for (int a : list_to_check) {
        if (a == element)
            return true;
    }
    return false;
}
int index(int element, vector<int> list_to_check){
    for (int i = 0; i < list_to_check.size(); ++i) {
        if (list_to_check[i] == element)
            return i;
    }
}

bool dfs(int v){
    Not_visited_vertexes.erase(Not_visited_vertexes.begin() + index(v, Not_visited_vertexes));
    Visited_vertexes.push_back(v);
    if (Color[v] == 1){
        Color[v] = 3;
        return true;
    }
    if (Color[v] == 2)
        return false;
    Color[v] = 1;
    checker_of_end = 0;
    for (int i = 0; i < graph[v].size(); ++i) {
        truth_checker = false;
        if (!in(graph[v][i], Visited_vertexes)){
                checker_of_end = 1;
                truth_checker = true;
            }
        if (truth_checker){
            if (dfs(graph[v][i])){
                return true;
            }
        }
    }
    if (checker_of_end == 0){
        if (graph[v].size() > 1){
            fout << "NO";
            exit(0);
        }
        int minimum = 100001;
        if (!Not_visited_vertexes.empty()){
            for(int a: Not_visited_vertexes){
                if (a < minimum)
                    minimum = a;
            }
            dfs(minimum);
        }
        if (Not_visited_vertexes.empty()){
            fout << "YES";
            exit(0);
        }
//            for(int a: graph[v]){
//                if (a < minimum)
//                    minimum = a;
//            }
//            dfs(minimum);
        }
}

void topological_sort(){
    for (int i = 0; i < n; ++i) {

        Visited_vertexes.clear();
        checker = 0;
        for (int i = 0; i < n; ++i) {
            Color[i] = 0;
        }
        bool Cycle = dfs(i);
        if (Cycle){
            fout << "NO\n";
            exit(0);
        }
    }
}

int main() {
    int a, b;
    fin >> n >> m;
    if (m == 0){
        fout << "YES";
        exit(0);
    }
    graph.resize(n, vector<int>());
    Color.resize(n);
    for (int i = 0; i < n; ++i) {
        Not_visited_vertexes.push_back(i);
        Color[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        fin >> a >> b;
        if (a != b){
            checker = 1;
            if (!in(b - 1, graph[a - 1])){
                graph[b - 1].push_back(a - 1);
                graph[a - 1].push_back(b - 1);
            }
        }
    }
    if (checker == 0){
        fout << "YES";
        exit(0);
    }
    topological_sort();
    fout << "YES";
    return 0;
}
