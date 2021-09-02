#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int main() {
    ifstream fin ("search2.in");
    ofstream fout ("search2.out");
    int number = 0, hash_const = 7, division_const = 5003, wanted_hash = 0;
    bool checker;
    vector <int> answer;
    string wanted_string, main_string;
    fin >> wanted_string;
    fin >> main_string;
    int main_string_size = main_string.size();
    int wanted_string_size = wanted_string.size();
    if (main_string_size < wanted_string_size){
        fout << 0;
        return 0;
    }
    int *hashes = new int[main_string_size - wanted_string_size + 1];
    hashes[0] = 0;
    for (int i = 0; i < wanted_string_size; ++i){
        hashes[0] += (int)main_string[i] * pow(hash_const, wanted_string_size - i - 1);
        wanted_hash += (int)wanted_string[i] * pow(hash_const, wanted_string_size - i - 1);
    }
    hashes[0] = hashes[0] % division_const;
    wanted_hash = wanted_hash % division_const;
    for (int i = 0; i < main_string_size - wanted_string_size; ++i){
        hashes[i + 1] = (int)(hashes[i] * hash_const - (int)main_string[i] * pow(hash_const, wanted_string_size) + (int)(main_string[i + wanted_string_size])) % division_const;
        if (hashes[i + 1] < 0)
            hashes[i + 1] += division_const;
    }
    for (int i = 0; i < main_string_size - wanted_string_size + 1; ++i) {
        if (hashes[i] != wanted_hash)
            continue;
        checker = true;
        for (int j = 0; j < wanted_string_size; ++j) {
            if (main_string[i + j] != wanted_string[j]){
                checker = false;
                break;
            }
        }
        if (checker){
            answer.push_back(i + 1);
            number += 1;
        }
    }
    fout << number << "\n";
    for (int i : answer)
        fout << i << " ";
    return 0;
}
