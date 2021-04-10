#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool BinSearch(vector<int> Array, int element, int n) {
    int l = -1;
    int r = n - 1;
    int middle;
    while (l < r - 1) {
        middle = (l + r) / 2;
        if (Array[middle] < element)
            l = middle;
        else
            r = middle;
    }
    if (Array[r] == element)
        return true;
    else
        return false;
}


template <typename T>
class Set{
private:
	vector<vector <T>> hash;
public:
	Set();
	void Insert(T);
	void Delete(T);
	bool Exists(T);
	int Hash(T);
};

template <typename T>
Set<T>::Set() {
	hash.resize(1000000, vector<int>());
}

template <typename T>
int Set<T>::Hash(T element) {
	int Code_of_hash = abs(element % 1000000);
	return Code_of_hash;
}

template <typename T>
void Set<T>::Insert(T element) {
    unsigned int Code_of_hash = Hash(element);
    if (hash[Code_of_hash].empty()) {
        hash[Code_of_hash].push_back(element);
        return;
    }
    for (unsigned int i = 0; i < hash[Code_of_hash].size(); i++) {
        if (hash[Code_of_hash][i] == element) {
            return;
        }
    }
    hash[Code_of_hash].push_back(element);
    int i = hash[Code_of_hash].size() - 1;
    while (hash[Code_of_hash][i] < hash[Code_of_hash][i - 1]) {
        swap(hash[Code_of_hash][i], hash[Code_of_hash][i - 1]);
        if (i == 1)
            break;
        i--;
    }
}

template <typename T>
void Set<T>::Delete(T element) {
	int Code_of_hash = Hash(element);
	if (hash[Code_of_hash].empty())
		return;
	for (int i = 0; i < hash[Code_of_hash].size(); i++) {
		if (hash[Code_of_hash][i] == element) {
			hash[Code_of_hash].erase(hash[Code_of_hash].begin() + i);
			return;
		}
	}
}


template <typename T>
bool Set<T>::Exists(T element) {
	int Code_of_hash = Hash(element);
	if (hash[Code_of_hash].empty())
		return false;
	if (BinSearch(hash[Code_of_hash], element, hash[Code_of_hash].size())) {
	    return true;
	}
	return false;
}


int main() {
	ifstream fin("set.in");
	ofstream fout("set.out");

	Set<int> Main_Set;
	string Command;
	int number;
	while (fin >> Command) {
		if (Command == "insert") {
			fin >> number;
			Main_Set.Insert(number);
		}
		else if (Command == "delete") {
			fin >> number;
			Main_Set.Delete(number);
		}
		else if (Command == "exists") {
			fin >> number;
            Main_Set.Exists(number) ? fout << "true\n" : fout << "false\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}