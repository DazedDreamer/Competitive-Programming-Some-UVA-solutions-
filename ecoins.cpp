#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int dp[40][500][500];
int infoval[41], conval[41];
int emod;

int solve(int idx, int x, int y){
    int temp = x*x + y*y;
    if(temp > emod*emod) return -1000000;
    if(temp == emod*emod) return 0;
    if(idx >= m) return 0;
    if(dp[idx][x][y] != -1) return dp[idx][x][y];
    int with = 1 + solve(idx,x+conval[idx], y+infoval[idx]);
    int without = solve(idx+1, x,y);

    if(with > 0 && without <= 0) return dp[idx][x][y] = with;
    if(with <= 0 && without > 0) return dp[idx][x][y] =without;
    return dp[idx][x][y] = min(with, without);
}

int main(){
    scanf("%d", &n);

    while(n--){
        memset(dp, -1, sizeof dp);
        scanf("%d%d", &m, &emod);
        for(int  i =0; i < m; i++){
            scanf("%d%d", &conval[i], &infoval[i]);
        }
        int ret = solve(0,0,0);
        if(ret<=0) printf("not possible\n");
        else printf("%d\n", ret);
    }
}
