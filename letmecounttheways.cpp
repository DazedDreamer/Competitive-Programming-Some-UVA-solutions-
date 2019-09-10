#include <cstdio>

#include <cstring>

long long target;
long long coins[5] = {1,5,10,25,50};

long long solve(long long idx, long long curramount, long long (&dp)[6][30001]){
    if(curramount == 0) return dp[idx][curramount] = 1;
    if(idx >= 5) return 0;
    if(coins[idx] > curramount) return 0;
    if(dp[idx][curramount] != -1) return dp[idx][curramount];

    return dp[idx][curramount] = solve(idx, curramount - coins[idx], dp) + solve(idx+1, curramount, dp);
}

int main(){
    long long dp[6][30001];

    memset(dp, -1, sizeof(dp));
    for(int j = 1; j <= 30000;j++){
        solve(0, j, dp);
    }

    while(scanf("%lld", &target) ==1){

        long long ret = dp[0][target];

        if(ret == 1)printf("There is only 1 way to produce %lld cents change.\n", target);
        else printf("There are %lld ways to produce %lld cents change.\n", ret, target);
    }
}
