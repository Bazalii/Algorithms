#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void Merge(vector<int>& Array, int left, int middle, int right, long long int& inversions) {
    int current_left = 0;
    int current_right = 0;
    vector <int> main_buffer;
    while (main_buffer.size() < right - left) {
        if (current_left + left >= middle || (current_right + middle < right && Array[current_right + middle] < Array[current_left + left])) {
            main_buffer.push_back(Array[current_right + middle]);
            current_right++;
            inversions += middle - current_left - left;
        }
        else {
            main_buffer.push_back(Array[current_left + left]);
            current_left++;
        }
    }
    for (int i = 0; i < current_left + current_right; i++)
        Array[left + i] = main_buffer[i];
}
 

void Merge_Sort(vector <int>& Array, int left, int right, long long int& inversions_check) {
    if (right - left < 2)
        return;
    Merge_Sort(Array, left, left + (right - left) / 2, inversions_check);
    Merge_Sort(Array, left + (right - left) / 2, right, inversions_check);
    Merge(Array, left, left + (right - left) / 2, right, inversions_check);
}


int main() {
    long long int inversions_number = 0;
    int size;
    ifstream fin("inversions.in");
    ofstream fout("inversions.out");
    fin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        fin >> arr[i];
    }
    Merge_Sort(arr, 0, size, inversions_number);
    fout << inversions_number;
    return 0;
}