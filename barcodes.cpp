#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
long long dp[51][51][51];

using namespace std;

long long solve(long long n, long long k, long long m){
    if(n < 0) return LLONG_MIN;

    if(k == 0){
        if(n > 0) return LLONG_MIN;
        return 1;
    }

    if(dp[n][k][m] != -1) return dp[n][k][m];

    long long total = 0;
    for(int i = 1; i <= m;i++){
        total = max(total, total + solve(n-i, k-1, m));
    }

    return dp[n][k][m] = total;
}

int main(){
    long long n,k,m;
    while(scanf("%lld%lld%lld", &n, &k, &m) == 3){
        memset(dp, -1, sizeof dp);
        printf("%lld\n", solve(n,k,m));
    }
    return 0;
}
