#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
vector<int> indegree;
vector<vector<int>> adjlist;
bool visited[26];
bool ispresent[26];
int counter[26];

void topsort(vector<int> res) {
    bool flag = false;
    
    for (int i = 0; i < 26; i++) {
        if (ispresent[i] && indegree[i] == 0 && !visited[i]) {
            visited[i] = true;
            
            for (auto it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                indegree[*it]--;
            }
            
            res.push_back(i);
            topsort(res);
            
            //reset
            visited[i] = false;
            res.erase(res.end() - 1);
            for (auto it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                indegree[*it]++;
            }
            flag = true;
        }
    }
    
    if (!flag) {
        if(res.size() == 0){
            cout<<"NO"<<endl;
            return;
        }
        for (int i = 0; i < res.size(); i++) {
            if (i == res.size() - 1) cout << (char) (res[i] + 'A');
            else cout << (char) (res[i] + 'A') << " ";
        }
        cout << endl;
    }
}


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char let;
        adjlist.assign(26, vector<int>());
        memset(visited, false, sizeof(visited));
        memset(ispresent, false, sizeof(ispresent));
        memset(counter, 0, sizeof(counter));
        indegree.assign(26, 0);
        while ((scanf("%c", &let) && let != '\n')) {
            ispresent[let - 'A'] = true;
        }
        
        bool flag = false;
        char i, op, j;
        while (scanf("%c%c%c", &i, &op, &j)) {
            int m = i - 'A';
            int n = j - 'A';
            
            if (op == '<') {
                adjlist[m].push_back(n);
                indegree[n]++;
            }
            if (op == '>') {
                adjlist[n].push_back(m);
                indegree[m]++;
            }
            char temp = getchar();
            if (temp == '\n') break;
        }
        
        getchar();
        vector<int> res;
        topsort(res);
        
        if(t)
            cout << endl;
    }
}
