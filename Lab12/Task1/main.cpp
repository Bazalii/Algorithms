#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int BinarySearch(const int *container, int value, int right){
    int left = -1;
    while (left < right - 1){
        int middle = (left + right) / 2;
        if (container[middle] < value)
            left = middle;
        else
            right = middle;
    }
    return right;
}

int main() {
    int k, length = 0;
    vector<int> answer;
    cin >> k;
    int *a = new int[k];
    int *position = new int[k + 1];
    int *d = new int[k + 1];
    int *previous = new int[k];
    for (int i = 0; i < k; ++i){
        cin >> a[i];
        position[i] = -1;
        previous[i] = -1;
    }
    position[k] = -1;
    d[0] = -1000000001;
    for (int i = 1; i <= k; ++i)
        d[i] = 1000000001;
    for (int i = 0; i < k; ++i) {
        int checker = BinarySearch(d, a[i], k);
        if (a[i] < d[checker] && d[checker - 1] < a[i]){
            d[checker] = a[i];
            previous[i] = position[checker - 1];
            position[checker] = i;
            length = max(checker, length);
        }
    }
    int t = position[length];
    while (t != -1) {
        answer.push_back(a[t]);
        t = previous[t];
    }
    reverse(answer.begin(), answer.end());
    cout << length << endl;
    for (int i : answer)
        cout << i << " ";
    return 0;
}