#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<bool> used;
vector<int> length;

void Dijkstra(int vertex){
    length[vertex] = 0;
    for (int i = 0; i < n; ++i) {
        vertex = -2;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (vertex == -2 || length[j] < length[vertex]))
                vertex = j;
        }
        if (length[vertex] == 100000001)
            break;
        used[vertex] = true;
        for (int k = 0; k < graph[vertex].size(); ++k) {
            if (length[vertex] + graph[vertex][k].second < length[graph[vertex][k].first])
                length[graph[vertex][k].first] = length[vertex] + graph[vertex][k].second;
        }
    }
}


int main() {
    int m, a, b, c;
    ifstream fin ("pathsg.in");
    ofstream fout ("pathsg.out");
    fin >> n >> m;
    graph.resize(n, vector<pair<int, int>>());
    used.resize(n);
    length.resize(n, 100000001);
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c;
        graph[a - 1].push_back(make_pair(b - 1, c));
    }
    for (int i = 0; i < n; ++i) {
        Dijkstra(i);
        for (int route : length){
            fout << route << " ";
        }
        fout << endl;
        for (int j = 0; j < n; ++j) {
            used[j] = false;
            length[j] = 100000001;
        }
    }
    return 0;
}
