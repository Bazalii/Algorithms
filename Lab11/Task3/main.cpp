#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<bool> used;
vector<long long int> length;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<>> main_queue;

void Mod_Dijkstra(){
    while(!main_queue.empty()){
        int current_vertex = main_queue.top().second;
        int current_length = main_queue.top().first;
        main_queue.pop();
        if (current_length > length[current_vertex])
            continue;
        for (int i = 0; i < graph[current_vertex].size(); ++i) {
            if (!used[graph[current_vertex][i].first] && (length[current_vertex] + graph[current_vertex][i].second < length[graph[current_vertex][i].first])){
                length[graph[current_vertex][i].first] = length[current_vertex] + graph[current_vertex][i].second;
                main_queue.push(make_pair(length[graph[current_vertex][i].first], graph[current_vertex][i].first));
            }
        }
        used[current_vertex] = true;
    }
}


int main() {
    int m, a, b, c;
    ifstream fin ("pathbgep.in");
    ofstream fout ("pathbgep.out");
    fin >> n >> m;
    graph.resize(n, vector<pair<int, int>>());
    used.resize(n);
    length.resize(n, 4000000001);
    for (int i = 0; i < m; i++) {
        fin >> a >> b >> c;
        graph[a - 1].push_back(make_pair(b - 1, c));
        graph[b - 1].push_back(make_pair(a - 1, c));
    }
    main_queue.push(make_pair(0, 0));
    length[0] = 0;
    Mod_Dijkstra();
    for (int route : length){
        fout << route << " ";
    }
    return 0;
}
