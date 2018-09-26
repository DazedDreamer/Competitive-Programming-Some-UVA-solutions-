#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int disc[10001];
int low[10001];
int dtime;
bool visited[10001];
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second > p2.second) return true;
    else if (p1.second == p2.second) {
        if (p1.first < p2.first) return true;
    }
    return false;
}
void doAP(vector<vector<int>>& adjlist, int source, vector<int>& componentcounter, vector<int>& parent){
    disc[source] = low[source] = dtime++;
    visited[source] = true;
    int children = 0;
    for(int i : adjlist[source]){
        if(!visited[i]){
            parent[i] = source;
            visited[i] = true;
            children++;
            doAP(adjlist, i, componentcounter, parent);
            low[source] = min(low[source], low[i]);
            if(parent[source] == -1 && children > 1)componentcounter[source] = children;
            if(parent[source] != -1 && low[i] >= disc[source])componentcounter[source] ++;
        } else if (i != parent[source]) low[source] = min(low[source], disc[i]);
    }
}
int main() {
    int v, m;
    while (scanf("%d%d", &v, &m) && m + v) {
        vector<vector<int>> adjlist(v, vector<int>());
        vector<int> parent(v, -1);
        int i, j;
        vector<int> componentcounter(v, 1);
        dtime = 0;
        while (scanf("%d%d", &i, &j) && i + j >= 0) {
            adjlist[i].push_back(j);
            adjlist[j].push_back(i);
        }
        memset(disc, -1, 10001);
        memset(low, -1, 10001);
        memset(visited, false, 10001);
        vector<pair<int, int>> pairs;
        for (int l = 0; l < v; l++) {
            if (!visited[l]) {
                dtime = 0;
                doAP(adjlist, l, componentcounter, parent);
            }
            pairs.push_back(make_pair(l, componentcounter[l]));
        }
        sort(pairs.begin(), pairs.end(), cmp);
        for (int b = 0; b < m; b++) {
            cout << pairs[b].first << " " << pairs[b].second << endl;
        }
        cout << endl;
    }
}
