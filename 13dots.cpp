#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int budget, n, prices[110], favor[110];

int dp[15000][100];


int getfav(int idx, int moneyspent){
    if(idx >= n){
      if(moneyspent > budget && moneyspent <= 2000) return -1000;
      return 0;
    }

    if(moneyspent + prices[idx] > budget){
      if(budget < 1800) return dp[moneyspent][idx] = 0;
      if(moneyspent+prices[idx] > budget + 200) return dp[moneyspent][idx] = 0;
    }
    if(dp[moneyspent][idx] != -1) return dp[moneyspent][idx];
    return dp[moneyspent][idx] = max(favor[idx] + getfav(idx + 1, moneyspent + prices[idx]), getfav(idx+1, moneyspent));
}

int main(){
    while(scanf("%d%d", &budget, &n) == 2){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &prices[i], &favor[i]);

        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", getfav(0,0));
    }
    return 0;
}
