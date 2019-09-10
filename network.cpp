// ARTICULATION POINTS

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool visited[101];
bool ap[101];
int lowest[101];
int disc[101];
int dtime = 0;
int parent[101];

void doAPprocedure(int currnode, vector<vector<int> > &adjlist) {
    disc[currnode] = lowest[currnode] = dtime++;

    visited[currnode] = true;

    int children = 0;

    for (int j = 0; j < adjlist[currnode].size();j++) {
        int i = adjlist[currnode][j];
        if (!visited[i]) {
            visited[i] = true;
            parent[i] = currnode;
            children++;
            doAPprocedure(i, adjlist);

            lowest[currnode] = min(lowest[i], lowest[currnode]);

            if (parent[currnode] == -1 && children > 1)ap[currnode] = true;

            else if (parent[currnode] != -1 && lowest[i] >= disc[currnode])ap[currnode] = true;
        } else lowest[currnode] = min(lowest[currnode], disc[i]);
    }
}

int main() {
    int n;

    while (scanf("%d\n", &n) && n) {
        //char line[500];
        vector<vector<int> > adjlist;
        adjlist.assign(n + 1, vector<int>());
        char l = '\0';
        int currnode = -1, currnum;
        while (scanf("%d", &currnum) && currnum) {
            if (currnode < 0) {
                currnode = currnum;
                continue;
            }
            adjlist[currnode].push_back(currnum);
            adjlist[currnum].push_back(currnode);
            l = getchar();
            if(l == '\n'){
                currnode = -1;
            }
        }
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        memset(lowest, -1, 101);
        memset(disc, -1, 101);
        dtime = 0;
        memset(ap, false, 101);


        for (int j = 1; j < n + 1; j++) {
            if (!visited[j]) doAPprocedure(j, adjlist);
        }
        int counter = 0;
        for (int j = 1; j < n + 1; j++) {
            if (ap[j]) counter++;
        }

        cout << counter << endl;
    }
}
