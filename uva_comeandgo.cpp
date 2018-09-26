#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
using namespace std;
const int MAXN = 2001;
int disc[MAXN], low[MAXN];
int dtime  = 0;
int visited[MAXN];
vector<vector<int>> adjlist;
int counter;
void tarjan(int u){
    disc[u] = low[u] = dtime++;
    visited[u] = 1;
    for(int v: adjlist[u]){
        if(!visited[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], disc[v]);
    }
    if(disc[u] == low[u]){
        counter++;
    }
}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        adjlist.clear();
        adjlist.assign(n+1, vector<int>());
        int i,j,p;
        while(m--){
            scanf("%d%d%d", &i, &j, &p);
            adjlist[i].push_back(j);
            if(p == 2){
                adjlist[j].push_back(i);
            }
        }
        counter = 0;
        memset(disc, 0, MAXN);
        memset(low, 0, MAXN);
        memset(visited, 0, MAXN);
        for(int i = 1; i < n; i++){
            if(!visited[i]){
                dtime = 0;
                tarjan(i);
            }
        }
        cout<<((counter > 1) ? "0" : "1") << endl;
    }
}

