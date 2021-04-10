#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<int> tree_id;
vector<int> degree;

void make_set(int vertex){
    tree_id[vertex] = vertex;
}

int find_set(int vertex){
    if (vertex == tree_id[vertex])
        return vertex;
    else
        return tree_id[vertex] = find_set(tree_id[vertex]);
}

void join_sets(int vertex1, int vertex2){
    vertex1 = find_set(vertex1), vertex2 = find_set(vertex2);
    if (vertex1 != vertex2){
        if (degree[vertex1] < degree[vertex2])
            swap(vertex1, vertex2);
        tree_id[vertex2] = vertex1;
        if (degree[vertex1] == degree[vertex2])
            degree[vertex1]++;
    }
}

int main() {
    int n, x, y, m;
    long long int weight = 0, edge_weight;
    ifstream fin ("spantree3.in");
    ofstream fout ("spantree3.out");
    fin >> n >> m;
    vector<pair<int, pair<int, int>>> graph;
    degree.resize(n);
    for (int i = 0; i < m; ++i) {
        fin >> x >> y >> edge_weight;
        graph.emplace_back(edge_weight, make_pair(x - 1, y - 1));
    }
    sort(graph.begin(), graph.end());
    tree_id.reserve(n);
    for (int i = 0; i < n; ++i)
        make_set(i);
    for (int i = 0; i < m; ++i) {
        edge_weight = graph[i].first;
        x = graph[i].second.first;
        y = graph[i].second.second;
        if (find_set(x) != find_set(y))
        {
            weight += edge_weight;
            join_sets(x, y);
        }
    }
    fout << weight;
    return 0;
}
