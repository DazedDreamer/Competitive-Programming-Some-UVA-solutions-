#include <iostream>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int cas = 0;
    while (scanf("%d\n", &n) != EOF) {
        map<string, int> indegree;
        map<string, vector<string>> adjlist;
        map<string, bool> drank;
        map<string, int> nametoint;
        char temp[55];
        while (n--) {
            scanf("%s", temp);
            adjlist[temp] = vector<string>();
            drank[temp] = false;
            indegree[temp] = 0;
            nametoint[temp] = n;
        }
        scanf("%d", &m);
        while (m--) {
            char i[55], j[55];
            scanf("%s %s", i, j);
            adjlist[i].push_back(j);
            indegree[j]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        for (auto it = indegree.begin(); it != indegree.end(); it++) {
            if ((*it).second == 0) {
                q.push(make_pair((*it).second, (*it).first));
            }
        }
        cout << "Case #" << ++cas << ": Dilbert should drink beverages in this order: ";
        vector<string> ans;
        while (!q.empty()) {
            auto it = q.top();
            string n = it.second;
            drank[n] = true;
            ans.push_back(n);
            q.pop();
            for (auto it = adjlist[n].begin(); it != adjlist[n].end(); it++) {
                indegree[*it]--;
                if (indegree[*it] == 0 && !drank[*it]) {
                    q.push(make_pair(indegree[*it], *it));
                }
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            if (i == ans.size() - 1)cout << ans[i] << ".";
            else cout << ans[i] << " ";
        }
        cout << endl<<endl;
    }
}

