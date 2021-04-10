#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int main() {
    ifstream fin ("negcycle.in");
    ofstream fout ("negcycle.out");
    int n, a, checker;
    vector<vector<pair<int, int>>> graph;
    vector<int> length, answer, route;
    fin >> n;
    graph.resize(n, vector<pair<int, int>>());
    length.resize(n, 2500001);
    route.resize(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            fin >> a;
            if (a < 2500001)
                graph[i].push_back(make_pair(j, a));
        }
    }
    for (int k = 0; k < n; ++k) {
        checker = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (length[i] + graph[i][j].second < length[graph[i][j].first]) {
                    length[graph[i][j].first] = max(length[i] + graph[i][j].second, -2500001);
                    route[graph[i][j].first] = i;
                    checker = graph[i][j].first;
                }
            }
        }
    }
    if (checker == -1)
        fout << "NO";
    else{
        for (int k = 0; k < n; ++k)
            checker = route[checker];
        int current_vertex = checker;
        while (true) {
            answer.push_back(current_vertex);
            if (answer.size() > 1 && current_vertex == checker)
                break;
            current_vertex = route[current_vertex];
        }
        fout << "YES" << endl << answer.size() << endl;
        reverse(answer.begin(), answer.end());
        for (int element : answer)
            fout << element + 1 << " ";
    }
    return 0;
}
