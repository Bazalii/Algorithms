#include <iostream>


using namespace std;

int main() {
    int n, *colors;
    cin >> n;
    colors = new int[n];
    int **d = new int *[n];
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
        d[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                d[i][j] = 1;
            else if (i > j)
                d[i][j] = 0;
        }
    }
    for (int i = n - 2; i > -1; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (colors[i] != colors[j])
                d[i][j] = (d[i][j - 1] + d[i + 1][j] - d[i + 1][j - 1]) % 1000000000;
            else
                d[i][j] = (d[i + 1][j] + d[i][j - 1] + 1) % 1000000000;
        }
    }
    cout << (d[0][n - 1] + 1000000000) % 1000000000 ;
    return 0;
}