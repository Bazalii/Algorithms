#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

template <typename T, typename U>
class Map{
private:
	vector<vector <T>> keys;
	vector<vector <U>> elements;
public:
	Map();
	void Insert(T, U);
	void Delete(U);
	T Exists(U);
	int Hash(U);
};

template <typename T, typename U>
Map<T, U>::Map() {
	keys.resize(1000000, vector<U>());
	elements.resize(1000000, vector<T>());
}

template <typename T, typename U>
int Map<T, U>::Hash(U key) {
    unsigned long long int Code_of_hash = 0;
    unsigned long long int p_pow = 1;
    for (int i = 0; i < key.size(); ++i) {
        Code_of_hash += ((abs((int)key[i])) * p_pow) % LLONG_MAX;
        p_pow = (p_pow * 31) % LLONG_MAX;
    }
    return Code_of_hash % 1000000;
}

template <typename T, typename U>
void Map<T, U>::Insert(T element, U key) {
    unsigned int Code_of_hash = Hash(key);
    if (elements[Code_of_hash].empty()) {
        elements[Code_of_hash].push_back(element);
        keys[Code_of_hash].push_back(key);
        return;
    }
    for (unsigned int i = 0; i < elements[Code_of_hash].size(); i++) {
        if (keys[Code_of_hash][i] == key && elements[Code_of_hash][i] == element) {
            return;
        }
        else if (keys[Code_of_hash][i] == key){
            elements[Code_of_hash][i] = element;
            return;
        }
    }
    elements[Code_of_hash].push_back(element);
    keys[Code_of_hash].push_back(key);
}

template <typename T, typename U>
void Map<T, U>::Delete(U key) {
	int Code_of_hash = Hash(key);
	if (elements[Code_of_hash].empty())
		return;
	for (int i = 0; i < elements[Code_of_hash].size(); i++) {
		if (keys[Code_of_hash][i] == key) {
			elements[Code_of_hash].erase(elements[Code_of_hash].begin() + i);
			keys[Code_of_hash].erase(keys[Code_of_hash].begin() + i);
			return;
		}
	}
}


template <typename T, typename U>
T Map<T, U>::Exists(U key) {
	int Code_of_hash = Hash(key);
	if (elements[Code_of_hash].empty())
		return "none";
	else {
        for (int i = 0; i < keys[Code_of_hash].size(); ++i) {
            if (key == keys[Code_of_hash][i]){
                return elements[Code_of_hash][i];
            }
        }
	}
	return "none";
}


int main() {
	ifstream fin("map.in");
	ofstream fout("map.out");
	Map<string, string> Main_Map;
	string Key1, Key2, Command;
	while (fin >> Command) {
		if (Command == "put") {
			fin >> Key1 >> Key2;
			Main_Map.Insert(Key2, Key1);
		}
		else if (Command == "delete") {
			fin >> Key1;
			Main_Map.Delete(Key1);
		}
		else if (Command == "get") {
			fin >> Key1;
			fout << Main_Map.Exists(Key1) << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}