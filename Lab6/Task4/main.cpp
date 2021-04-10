#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

template <typename T, typename U>
class Multi_Map{
private:
    struct Node{
        U key;
        vector<vector<T>> elements;
        Node();
        int size;
    };
	vector<vector <Node*>> cells;
public:
	Multi_Map();
	void Insert(T, U);
	void Delete(U, T);
	void Exists(U, ofstream&);
	int Hash(U);
	void Delete_all(U key);
};

template <typename T, typename U>
Multi_Map<T, U>::Node::Node(){
//    elements.reserve(10000);
    size = 0;
}

template <typename T, typename U>
Multi_Map<T, U>::Multi_Map() {
//	cells.reserve(10000);
}


template <typename T, typename U>
int Multi_Map<T, U>::Hash(U key) {
    unsigned long long int Code_of_hash = 0;
    unsigned long long int p_pow = 1;
    for (int i = 0; i < key.size(); ++i) {
        Code_of_hash += ((abs((int)key[i] - (int)'a' + 1)) * p_pow) % LLONG_MAX;
        p_pow = (p_pow * 31) % LLONG_MAX;
    }
    return Code_of_hash % 10000;
}

template <typename T, typename U>
void Multi_Map<T, U>::Insert(T element, U key) {
    unsigned int Code_of_hash = Hash(key);
    unsigned int Hash_of_element = Hash(element);
    for (unsigned int i = 0; i < cells[Code_of_hash].size(); i++) {
        if (cells[Code_of_hash][i]->key == key) {
            for (unsigned int j = 0; j < cells[Code_of_hash][i]->elements[Hash_of_element].size(); ++j) {
                if (cells[Code_of_hash][i]->elements[Hash_of_element][j] == element){
                    return;
                }
            }
            typename vector<vector<T>>::iterator it;
            for (it = cells[Code_of_hash][i]->elements.end(); it < cells[Code_of_hash][i]->elements.begin() + Hash_of_element; ++it) {
                vector<T> V;
                cells[Code_of_hash][i]->elements.push_back(V);
            }
            cells[Code_of_hash][i]->elements[Hash_of_element].push_back(element);
            cells[Code_of_hash][i]->size++;
            return;
        }
    }
    Node* Temp = new Node();
    typename vector<vector<Node*>>::iterator it2;
    for (it2 = cells.end(); it2 < cells.begin() + Hash_of_element; ++it2) {
        vector<Node*> V2;
        cells.push_back(V2);
    }
    cells[Code_of_hash].push_back(Temp);
    Temp->key = key;
    Temp->elements[Hash_of_element].push_back(element);
    Temp->size++;
}

template <typename T, typename U>
void Multi_Map<T, U>::Delete(U key, T element) {
	unsigned int Code_of_hash = Hash(key);
	unsigned int Hash_of_element = Hash(element);
	if (cells[Code_of_hash].empty())
		return;
	for (int i = 0; i < cells[Code_of_hash].size(); i++) {
		if (cells[Code_of_hash][i]->key == key) {
		    for (unsigned int j = 0; j < cells[Code_of_hash][i]->elements[Hash_of_element].size(); ++j) {
                if (cells[Code_of_hash][i]->elements[Hash_of_element][j] == element){
                    cells[Code_of_hash][i]->elements[Hash_of_element].erase(cells[Code_of_hash][i]->elements[Hash_of_element].begin() + j);
                    cells[Code_of_hash][i]->size--;
                    if  (cells[Code_of_hash][i]->size == 0){
                        cells[Code_of_hash].erase(cells[Code_of_hash].begin() + i);
                    }
                }
            }
			return;
		}
	}
}

template <typename T, typename U>
void Multi_Map<T, U>::Delete_all(U key) {
    int Code_of_hash = Hash(key);
    if (cells[Code_of_hash].empty())
		return;
    for (unsigned int i = 0; i < cells[Code_of_hash].size(); i++) {
        if (cells[Code_of_hash][i]->key == key) {
            cells[Code_of_hash].erase(cells[Code_of_hash].begin() + i);
            }
            return;
        }
}


template <typename T, typename U>
void Multi_Map<T, U>::Exists(U key, ofstream& fout) {
	int Code_of_hash = Hash(key);
	if (cells[Code_of_hash].empty()){
	    fout << 0 << endl;
	    return;
    }
	else {
        for (int i = 0; i < cells[Code_of_hash].size(); ++i) {
            if (key == cells[Code_of_hash][i]->key){
                fout << cells[Code_of_hash][i]->size << " ";
                for (unsigned int j = 0; j < cells[Code_of_hash][i]->elements.size(); ++j) {
                    for (int k = 0; k < cells[Code_of_hash][i]->elements[j].size(); ++k) {
                            fout << cells[Code_of_hash][i]->elements[j][k] << " ";
                    }
                }
                fout << endl;
                return;
            }
        }
	}
	fout << 0 << endl;
}


int main() {
	ifstream fin("multimap.in");
	ofstream fout("multimap.out");
	Multi_Map<string, string> Main_Map;
	string Key1, Key2, Command;
	while (fin >> Command) {
		if (Command == "put") {
			fin >> Key1 >> Key2;
			Main_Map.Insert(Key2, Key1);
		}
		else if (Command == "delete") {
			fin >> Key1 >> Key2;
			Main_Map.Delete(Key1, Key2);
		}
		else if (Command == "deleteall") {
			fin >> Key1;
			Main_Map.Delete_all(Key1);
		}
		else if (Command == "get") {
			fin >> Key1;
			Main_Map.Exists(Key1, fout);
		}
	}
	fin.close();
	fout.close();
	return 0;
}