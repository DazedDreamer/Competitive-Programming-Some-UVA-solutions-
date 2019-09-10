#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adjlist;
int  color[205]; // set to 0
int vis[205]; // set to 0
int finalans =0;
void counter(int junction){
    queue<int> q;
    q.push(junction);
    memset(color, 0, sizeof color);
    int black = 0, white = 0;
    color[junction] = 1;
    vis[junction] = 1;

    while(!q.empty() && finalans >= 0){
        int currj = q.front(); q.pop();
//        printf("currj  :%d\n", currj);
        if(color[currj]) black++; else white++;
//        printf("black white, %d %d\n", black, white);

        for(int i = 0; i < adjlist[currj].size(); i++){
            int currneigh = adjlist[currj][i];
//            printf("currneigh %d\n", currneigh);
            if(!vis[currneigh]){
                vis[currneigh] =1;
                color[currneigh] = 1 - color[currj];
                q.push(currneigh);
            } else if(color[currneigh] == color[currj]){finalans = -1; break;}
        }
    }

    if(finalans < 0) return;
    finalans += max(1, min(black, white));
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int v, e;
        finalans = 0;
        scanf("%d%d", &v, &e);
        adjlist.assign(v, vector<int>());
        int first, second;
        for(int i = 0; i < e; i++){
            scanf("%d%d", &first, &second);
            adjlist[first].push_back(second);
            adjlist[second].push_back(first);
        }

//        if(!e){ printf("1\n"); continue;}
        memset(vis, 0, sizeof vis);

        for(int i = 0; i < v && finalans >= 0;i++){
            if(!vis[i]){
                counter(i);
            }
        }

        if(finalans < 0) printf("-1\n");
        else printf("%d\n", finalans);
    }
}
