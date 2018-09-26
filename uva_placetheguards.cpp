#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<vector<int>> adjlist;
        int n, e;
        scanf("%d%d", &n, &e);
        adjlist.assign(n, vector<int>());
        while (e--) {
            int i, j;
            scanf("%d%d", &i, &j);
            adjlist[i].push_back(j);
            adjlist[j].push_back(i);
        }
        int color[n];
        int soldiers = 0;
        bool flag = true;
        memset(color, -1, sizeof(color));
        for (int i = 0; i < n && flag; i++) {
            if (color[i] < 0) {
                int count[2];
                count[0] = count[1] = 0;
                queue<int> q;
                q.push(i);
                color[i] = 1;
                count[color[i]]++;
                while (!q.empty() && flag) {
                    int m = q.front();
                    q.pop();
                    for (int j:adjlist[m]) {
                        if (color[j] < 0) {
                            color[j] = 1 - color[m];
                            count[color[j]]++;
                            q.push(j);
                        } else if (color[j] == color[m]) {
                            flag = false;
                        }
                    }
                }
                soldiers += max(1,min(count[0], count[1]));
            }
        }
        if (!flag) cout << -1 << endl;
        else cout << soldiers << endl;
    }
    return 0;
}
