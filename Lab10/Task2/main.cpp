#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
    int n, x, y, maximum = 800000001;
    double weight = 0;
    fin >> n;
    vector<vector<double>> graph(n);
    vector<bool> used(n);
    vector<int> minimum_for_current(n, maximum) , end_of_minimum_edge(n, -1);
    vector<pair<int, int>> vertexes;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        vertexes.emplace_back(x, y);
        graph[i].resize(n, maximum);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = pow(vertexes[i].first - vertexes[j].first, 2) + pow(vertexes[i].second - vertexes[j].second, 2);
        }
    }
    vertexes.clear();
    minimum_for_current[0] = 0;
    for (int i = 0; i < n; ++i) {
        int cur_vertex = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (cur_vertex == -1 || minimum_for_current[j] < minimum_for_current[cur_vertex]))
                cur_vertex = j;
        used[cur_vertex] = true;
        for (int adj_vertex = 0; adj_vertex < n; ++adj_vertex)
            if (graph[cur_vertex][adj_vertex] < minimum_for_current[adj_vertex] && cur_vertex != adj_vertex && !used[adj_vertex]) {
                    minimum_for_current[adj_vertex] = graph[cur_vertex][adj_vertex];
            }
    }
    for (int i : minimum_for_current) {
        weight += sqrt(i);
    }
    fout << setprecision(10) << weight << endl;
}
