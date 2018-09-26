// CLAW decomposition

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int main() {
    int v;
    while (scanf("%d", &v) && v) {
        vector<vector<int>> adjlist(v+1, vector<int>());
        int startvertex = -1;
        int i, j;
        while (scanf("%d%d", &i, &j) && i+j) {
            if (startvertex < 0) startvertex = i;
            adjlist[i].push_back(j);
            adjlist[j].push_back(i);
        }
        queue<int> q;
        q.push(startvertex);
        int color[v+1];
        memset(color, -1, sizeof(color));
        color[startvertex] = 1;
        bool f = true;
        while (!q.empty() && f) {
            int curr = q.front();
            q.pop();
            for (int j:adjlist[curr]) {
                if (color[j] == color[curr]) f = false;
                if (color[j] < 0) {
                    color[j] = 1 - color[curr];
                    q.push(j);
                }
            }
        }
        if (!f) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
