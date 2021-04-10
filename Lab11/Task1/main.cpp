#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<bool> used;
vector<long long int> length;

void Dijkstra(int vertex){
    length[vertex] = 0;
    for (int i = 0; i < n; ++i) {
        vertex = -2;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (vertex == -2 || length[j] < length[vertex]))
                vertex = j;
        }
        if (length[vertex] == 2000000000001)
            break;
        used[vertex] = true;
        for (int k = 0; k < graph[vertex].size(); ++k) {
            if (length[vertex] + graph[vertex][k].second < length[graph[vertex][k].first])
                length[graph[vertex][k].first] = length[vertex] + graph[vertex][k].second;
        }
    }
}


int main() {
    int s, f, a;
    ifstream fin ("pathmgep.in");
    ofstream fout ("pathmgep.out");
    fin >> n >> s >> f;
    graph.resize(n, vector<pair<int, int>>());
    used.resize(n);
    length.resize(n, 2000000000001);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            fin >> a;
            if (a > 0)
                graph[i].push_back(make_pair(j, a));
        }
    }
    Dijkstra(s - 1);
    if  (length[f - 1] != 2000000000001)
        fout << length[f - 1];
    else
        fout << -1;
    return 0;
}
