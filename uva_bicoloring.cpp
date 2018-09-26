#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int main(){
    int n, edges;
    while((scanf("%d%d", &n, &edges)) == 2){
        vector<vector<int>> adjlist;
        adjlist.assign(n, vector<int>());
        int startvertex = -1;
        while(edges--){
            int i, j;
            scanf("%d%d", &i, &j);
            if(startvertex < 0) startvertex = i;
            adjlist[i].push_back(j);
            adjlist[j].push_back(i);
        }
        int color[n], visited[n];
        memset(color, -1, sizeof(color));
        memset(visited, false, sizeof(visited));
        color[startvertex] = 1;
        queue<int> q;
        q.push(startvertex);
        bool flag = true;
        while(!q.empty()){
            int curr = q.front();
            visited[curr] = true;
            q.pop();
            for(vector<int>::iterator it = adjlist[curr].begin(); it != adjlist[curr].end(); it++){
                if(!visited[*it]) {
                    if (color[*it] != color[curr]) {
                        color[*it] = 1 - color[curr];
                        q.push(*it);
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        
        if(!flag)cout<<"NOT BICOLORABLE.";
        else cout<<"BICOLORABLE.";
        cout<<endl;
    }
    return 0;
}
