#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int adjmat[MAX][MAX], V[MAX], L[MAX], n, m, dtime;

void dfs(int u, int v) {
    V[v] = L[v] = ++dtime;
    for(int i = 1; i <= n; i++) {
        if(adjmat[v][i]) {
            if(!V[i]){
                dfs(v, i);
                L[v] = min(L[v], L[i]);
                if(L[i] <= V[v]) {
                    adjmat[i][v] = 0;
                }
            } else if(i != u) {
                L[v] = min(L[v], V[i]);
                adjmat[i][v] = 0;
            }
        }
    }
}

int main() {
    int tt = 0;
    while(cin >> n >> m, n|m) {
        memset(adjmat, 0, sizeof(adjmat));
        memset(V, 0, sizeof(V));
        memset(L, 0, sizeof(L));
        dtime = 0;

        cout << ++tt << endl << endl;

        for(int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            adjmat[a][b] = adjmat[b][a] = 1;
        }

        for(int i=1; i<=n; i++)
            if (!V[i])
                dfs(i, i);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if (adjmat[i][j])
                    cout << i << " " << j <<endl;

        cout << "#" << endl;
    }
}
