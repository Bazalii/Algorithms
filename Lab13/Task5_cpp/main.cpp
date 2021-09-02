#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class vertex{
private:
    int next;
    int p;
    bool leaf;
    char pch;
    int link;
    int move;
public:
    vertex();
    int get_next(){
        return this->next;
    }
};

void add(string current_string, int root){
    int i = 0;
    int s = root;
    while ()
}


int main() {
    ifstream fin ("search4.in");
    ofstream fout ("search4.out");
    int n;
    fin >> n;
    return 0;
}
