#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



long long arr[500];
long long dp[201][22][11];

long long m,d;
long long getsumofallsubsets(long long idx, long long currsummodd, long long numleft, long long n){
  if(numleft == 0) {if(currsummodd == 0) return 1; else return 0;}

  if(idx >= n) return 0;


  if(dp[idx][currsummodd][numleft] != -1) return dp[idx][currsummodd][numleft];
  long long temp = currsummodd + arr[idx];
  temp%=d;
  if(temp < 0) temp += d;
  return (dp[idx][currsummodd][numleft] = getsumofallsubsets(idx+1, temp, numleft - 1, n) +
        getsumofallsubsets(idx+1, currsummodd, numleft, n));
}
int main(){
  long long n,q, set = 0;

  while(scanf("%lld%lld", &n, &q) && n+q){

    for(long long i = 0; i < n;i++)scanf("%lld", &arr[i]);
    long long query =0;

    printf("SET %lld:\n", ++set);

    while(q--){
      scanf("%lld%lld", &d , &m);
      memset(dp, -1, sizeof(dp));
      printf("QUERY %lld: %lld\n", ++query, getsumofallsubsets(0, 0, m, n));
    }

  }
  return 0;
}
