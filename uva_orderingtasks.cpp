#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;
bool visited[101];
vector<vector<int>> adjlists;
void topsort(stack<int>& st, int source){
    visited[source] = true;
    for(auto it = adjlists[source].begin(); it != adjlists[source].end(); it++){
        if(!visited[*it]) topsort(st, *it);
    }
    st.push(source);
}
int main(){
    int n,m;
    while(scanf("%d%d", &n, &m) && m+n) {
        adjlists.assign(n + 1, vector<int>());
        memset(visited, false, sizeof(visited));
        while (m--) {
            int i, j;
            scanf("%d%d", &i, &j);
            adjlists[i].push_back(j);
        }
        stack<int> j;
        for (int i = 1; i < n + 1; i++) {
            if (!visited[i]) topsort(j, i);
        }
        while(!j.empty()){
            cout<<j.top()<<" ";
            j.pop();
        }
        cout << endl;
    }
}
