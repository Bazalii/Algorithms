#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

template <typename T, typename U>
class Linked_Map{
private:
    struct Node{
        U key;
        T element;
        Node *prev;
        Node *next;
        Node(T, U, Node*, Node*);
    };
    Node* previous;
	vector<vector <Node*>> cells;
public:
	Linked_Map();
	void Insert(T, U);
	void Delete(U);
	T Exists(U);
	int Hash(U);
	T Prev(U);
	T Next(U);
};

template <typename T, typename U>
Linked_Map<T, U>::Node::Node(T e, U k, Node* p, Node* n){
    key = k;
    element = e;
    prev = p;
    next = n;
}

template <typename T, typename U>
Linked_Map<T, U>::Linked_Map() {
	cells.resize(1000005, vector<Node*>());
	previous = NULL;
}


template <typename T, typename U>
int Linked_Map<T, U>::Hash(U key) {
    unsigned long long int Code_of_hash = 0;
    unsigned long long int p_pow = 1;
    for (int i = 0; i < key.size(); ++i) {
        Code_of_hash += ((abs((int)key[i])) * p_pow) % LLONG_MAX;
        p_pow = (p_pow * 31) % LLONG_MAX;
    }
    return Code_of_hash % 1000000;
}

template <typename T, typename U>
void Linked_Map<T, U>::Insert(T element, U key) {
    unsigned int Code_of_hash = Hash(key);
    if (cells[Code_of_hash].empty()) {
        Node* Temp = new Node(element, key, previous, NULL);
        cells[Code_of_hash].push_back(Temp);
        if (previous != NULL){
            previous->next = Temp;
        }
        previous = Temp;
        return;
    }
    for (unsigned int i = 0; i < cells[Code_of_hash].size(); i++) {
        if (cells[Code_of_hash][i]->key == key && cells[Code_of_hash][i]->element == element) {
            return;
        }
        else if (cells[Code_of_hash][i]->key == key){
            cells[Code_of_hash][i]->element = element;
            return;
        }
    }
    Node* Temp = new Node(element, key, previous, NULL);
    cells[Code_of_hash].push_back(Temp);
    previous->next = Temp;
    previous = Temp;
}

template <typename T, typename U>
void Linked_Map<T, U>::Delete(U key) {
	int Code_of_hash = Hash(key);
	if (cells[Code_of_hash].empty())
		return;
	for (int i = 0; i < cells[Code_of_hash].size(); i++) {
		if (cells[Code_of_hash][i]->key == key) {
		    if (cells[Code_of_hash][i]->prev != NULL){
		        cells[Code_of_hash][i]->prev->next = cells[Code_of_hash][i]->next;
		    }
		    if (cells[Code_of_hash][i]->next != NULL){
		        cells[Code_of_hash][i]->next->prev = cells[Code_of_hash][i]->prev;
		    }
		    if (cells[Code_of_hash][i]->prev == NULL && cells[Code_of_hash][i]->next == NULL){
		        previous = NULL;
		    }
		    if (cells[Code_of_hash][i] == previous){
		        previous = cells[Code_of_hash][i]->prev;
		    }
			cells[Code_of_hash].erase(cells[Code_of_hash].begin() + i);
			return;
		}
	}
}


template <typename T, typename U>
T Linked_Map<T, U>::Exists(U key) {
	int Code_of_hash = Hash(key);
	if (cells[Code_of_hash].empty())
		return "none";
	else {
        for (int i = 0; i < cells[Code_of_hash].size(); ++i) {
            if (key == cells[Code_of_hash][i]->key){
                return cells[Code_of_hash][i]->element;
            }
        }
	}
	return "none";
}


template <typename T, typename U>
T Linked_Map<T, U>::Prev(U key) {
    int Code_of_hash = Hash(key);
	if (cells[Code_of_hash].empty())
		return "none";
	else {
        for (int i = 0; i < cells[Code_of_hash].size(); ++i) {
            if (key == cells[Code_of_hash][i]->key){
                if (cells[Code_of_hash][i]->prev == NULL)
                    return "none";
                return cells[Code_of_hash][i]->prev->element;
            }
        }
	}
	return "none";
}

template <typename T, typename U>
T Linked_Map<T, U>::Next(U key) {
    int Code_of_hash = Hash(key);
	if (cells[Code_of_hash].empty())
		return "none";
	else {
        for (int i = 0; i < cells[Code_of_hash].size(); ++i) {
            if (key == cells[Code_of_hash][i]->key){
                if (cells[Code_of_hash][i]->next == NULL)
                    return "none";
                return cells[Code_of_hash][i]->next->element;
            }
        }
	}
	return "none";
}


int main() {
	ifstream fin("linkedmap.in");
	ofstream fout("linkedmap.out");
	Linked_Map<string, string> Main_Map;
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
		else if (Command == "prev") {
			fin >> Key1;
			fout << Main_Map.Prev(Key1) << endl;
		}
		else if (Command == "next") {
			fin >> Key1;
			fout << Main_Map.Next(Key1) << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}