// DOMINOS

#include <vector>
#include <string.h>
#include <stack>
#include <iostream>
#define MAXN 100001
using namespace std;
int disc[MAXN];
void dfs(int source, vector<vector<int>>& adjlists, stack<int>& st){
    disc[source] = 1;
    for(int j :adjlists[source]){
        if(disc[j] == -1) dfs(j, adjlists, st);
    }
    st.push(source);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> adjlists(n+1, vector<int>());
        while(m--){
            int i,j;
            scanf("%d%d", &i, &j);
            adjlists[i].push_back(j);
        }
        memset(disc, -1, MAXN);
        stack<int> st;
        int counter = 0;
        for(int i = 1; i < n+1; i++){
            if(disc[i] == -1) {
                dfs(i, adjlists, st);
            }
        }
        memset(disc, -1, MAXN);
        stack<int> temp;
        while(!st.empty()){
            if(disc[st.top()] == -1){
                dfs(st.top(), adjlists, temp);counter++;
            }
            st.pop();
        }
        cout<<counter<<endl;
    };
}
