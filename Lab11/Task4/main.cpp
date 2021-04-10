#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<vector<pair<int,long long int>>> graph;
vector<bool> used;

void dfs(long long vertex){
    used[vertex] = true;
    for (auto i : graph[vertex]) {
        if (!used[i.first])
            dfs(i.first);
    }
}

int main() {
    int m, a, b, s, n;
    long long int c;
    long long const int maximum = 2 * 1e18;
    vector<long long int> length, route;
    ifstream fin ("path.in");
    ofstream fout ("path.out");
    fin >> n >> m >> s;
    graph.resize(n, vector<pair<int,long long int>>());
    used.resize(n, false);
    length.resize(n, maximum);
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c;
        graph[a - 1].push_back(make_pair(b - 1, c));
    }
    length[s - 1] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if ((length[i] + graph[i][j].second < length[graph[i][j].first]) && length[i] < maximum)
                    length[graph[i][j].first] = length[i] + graph[i][j].second > -maximum ? length[i] + graph[i][j].second : -maximum;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if ((length[i] + graph[i][j].second < length[graph[i][j].first]) && !used[graph[i][j].first] && length[i] < maximum)
                dfs(graph[i][j].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (length[i] == maximum)
            fout << "*" << endl;
        else if (used[i])
            fout << "-" << endl;
        else
            fout << length[i] << endl;
    }
    return 0;
}
