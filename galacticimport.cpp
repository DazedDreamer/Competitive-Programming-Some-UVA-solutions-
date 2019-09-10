#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int vis[26];
double val[26];

void initialize() {
    memset(val, 0, sizeof val);
    memset(vis, 0, sizeof vis);
}

double getval(int node, vector<vector<char> > (&adjlist)) {
    queue<int> q;
    q.push(-1);
    q.push(node);
    int exponent = -1;
    double ret = val[node];
    int canexport = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr < -1) break;
        if (curr == -1) {
            if(q.empty()){canexport = 0; break;}
            exponent += 1;
            if(exponent > 1){
                ret -= 0.05*ret;
            }
            q.push(-1);
            continue;
        }
        vis[curr] = 1;
        for (int i = 0; i < adjlist[curr].size(); i++) {
            int currneigh = adjlist[curr][i] - 'A';
            if (currneigh >= 0) {
                if (!vis[currneigh]) q.push(currneigh);
            } else {
                q.push(currneigh);
            }
        }
    }

    if(!canexport) return 0;
    return ret;
}

int main() {
    int n;
    while (scanf("%d\n", &n) == 1) {
        initialize();
        vector<vector<char> > adjlist;

        adjlist.assign(26, vector<char>());

        double value;
        char planet;
        string neigh;

        for (int i = 0; i < n; i++) {
            scanf("%c %lf ", &planet, &value);
            getline(cin, neigh);
            value *= 100;
            value = round(value);
            value /= 100;
            val[planet - 'A'] = value;
            for (int j = 0; j < neigh.size(); j++) {
                adjlist[planet - 'A'].push_back(neigh[j]);
                if(neigh[j] - 'A' >= 0)
                adjlist[neigh[j] - 'A'].push_back(planet);
            }

        }

        // now run bfs for all vertices and get the value
        int ans;
        double maxval = -1;
        for (int i = 0; i < 26; i++) {
            if (val[i] > 0) {
                memset(vis, 0, sizeof vis);
                double ret = getval(i, adjlist);
                if (ret > maxval) {
                    maxval = ret;
                    ans = i;
                }
            }
        }

        printf("Import from %c\n", ans + 'A');
    }
}
