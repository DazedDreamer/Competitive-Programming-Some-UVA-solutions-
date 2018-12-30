#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>

using std::vector;
using std::pair;
using std::map;
using std::make_pair;
using std::cout;
using std::endl;

map<pair<int, int>, bool> visited;
pair<int, int> left, right;
bool is_done = false;

void find(vector<pair<int, int>> (&dominoes), int previousnumber, int numberofspaces, int spacesfilled) {
    if (spacesfilled == numberofspaces) {
        if(previousnumber == right.first) is_done  = true;
        return;
    }

    if (!is_done) {

        for (auto &currdomino: dominoes) {
            if (!visited[currdomino]) {
                if (currdomino.first == previousnumber) {
                    visited[currdomino] = true;
                    find(dominoes, currdomino.second, numberofspaces, spacesfilled + 1);
                    visited[currdomino] = false;
                }

                if (currdomino.second == previousnumber) {
                    visited[currdomino] = true;
                    find(dominoes, currdomino.first, numberofspaces, spacesfilled + 1);
                    visited[currdomino] = false;
                }
            }
        }
    }
}

int main() {
    int n, m;
    vector<pair<int, int>> dominoes;


    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        int x, y;
        int i = 2;
        visited.clear();
        dominoes.clear();
        m+=2;
        while (m--) {
            scanf("%d%d", &x, &y);
            dominoes.emplace_back(x, y);
            visited[make_pair(x, y)] = false;
            if (i == 2) left = make_pair(x, y);
            if (i == 1) right = make_pair(x, y);
            i--;
        }

        visited[left] = visited[right] = true;
        is_done = false;
        find(dominoes, left.second, n, 0);
        cout << ((is_done) ? "YES" : "NO") << endl;
    }


    return 0;
}
