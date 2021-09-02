#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

int main() {
    ifstream fin ("knight2.in");
    ofstream fout ("knight2.out");
    int n, m, i = 0, j = 0;
    vector<vector<int>> answer;
    fin >> n >> m;
    answer.resize(n, vector<int>(m));
    answer[i][j] = 1;
    while (i != n - 1 || j != m - 1) {
        int first = i, second = j;
        while (first > -1 && second < m){
            if (first - 2 > -1 && second + 1 < m)
                answer[first][second] += answer[first - 2][second + 1];
            if (first - 1 > -1 && second - 2 > -1)
                answer[first][second] += answer[first - 1][second - 2];
            if (first + 1 < n && second - 2 > -1)
                answer[first][second] += answer[first + 1][second - 2];
            if (first - 2 > -1 && second - 1 > -1)
                answer[first][second] += answer[first - 2][second - 1];
            first -= 1;
            second += 1;
        }
        if (i == n - 1)
            j += 1;
        else
            i += 1;
    }
    if (n - 2 > -1 && m - 3 > -1)
        answer[n - 1][m - 1] += answer[n - 2][m - 3];
    if (n - 3 > -1 && m - 2 > -1)
        answer[n - 1][m - 1] += answer[n - 3][m - 2];
    fout << answer[n - 1][m - 1];
    return 0;
}