// BRIDGES


#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[101];
int lowest[101];
int disc[101];
int dtime = 0;
int parent[101];
void doAPprocedure(int currnode, vector<vector<int>> &adjlist, vector<pair<int, int>>& ap) {
    disc[currnode] = lowest[currnode] = dtime++;
    visited[currnode] = true;
    for (int i:adjlist[currnode]) {
        if (!visited[i]) {
            visited[i] = true;
            parent[i] = currnode;
            doAPprocedure(i, adjlist, ap);
            lowest[currnode] = min(lowest[i], lowest[currnode]);
            if (lowest[i] > disc[currnode]){
                ap.push_back(make_pair(min(currnode, i), max(currnode, i)));
            }
        } else if(i != parent[currnode]){
            lowest[currnode] = min(lowest[currnode], disc[i]);
        }
    }
}
int main() {
    int n;
    
    while (scanf("%d\n", &n) != EOF) {
        //char line[500];
        vector<vector<int>> adjlist;
        adjlist.assign(n, vector<int>());
        char l = '\0';
        int currnode, connections;
        int m = 0;
        while(n--){
            scanf("%d (%d)", &currnode, &connections);
            while(connections--){
                int e;
                scanf("%d", &e);
                adjlist[currnode].push_back(e);
            }
        }
        memset(visited, false, sizeof(visited));
        memset(lowest, -1, 101);
        memset(disc, -1, 101);
        memset(parent, -1, 101);
        dtime = 0;
        vector<pair<int, int>> ap;
        
        
        for (int j = 0; j < adjlist.size(); j++) {
            if (!visited[j])
                doAPprocedure(j, adjlist, ap);
        }
        
        
        cout<<ap.size()<<" critical links\n";
        sort(ap.begin(), ap.end());
        for(auto it: ap){
            cout<<it.first<<" - "<<it.second<<endl;
        }
        
        puts("");
    }
}
