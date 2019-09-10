#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[101][101];
int solve(int n, int k){
  if(n == 0) return 1;

  if(k == 0){
    if(n > 0) return -1000000;
    return 1;
  }
  if(dp[n][k] != -1) return dp[n][k];
  int total = 0;
  for(int i = 0; i <= n; i++){
    total = max(total, total + solve(n-i, k-1));
    total = total%1000000;
  }

  return dp[n][k] = total;
}


int main(){
  int n,k;

  while(scanf("%d%d", &n, &k) && n+k){
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(n,k));
  }
}
