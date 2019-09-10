#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int coins[] = {5,10,20,50,100,200};
int dp[2000][10]; // d(i,j) min coins to make i from coins[0...j-1]
int dp1[2000][10][251];
int quantity[10];
int n;

int fillup(){
  // base case
  for(int i =0 ;i < 2000; i++) for (int j = 0; j < 10; j++) dp[i][j] = 1000;
  // fill(dp, dp + 2000*10, 1000);
  // number of ways to make zero is zero
  for(int i = 0; i < 10; i ++){
    dp[0][i] = 0;
  }

  // general cases
  for(int i = 1; i < 2000;i++){
    for(int j = 0; j < 10; j++){
      if(coins[j] > i) dp[i][j] = dp[i][j-1];
      else{
        dp[i][j] = min(dp[i-coins[j]][j] + 1, dp[i][j-1]);
      }
    }
  }

}

int fillup2(){
  for(int i =0 ;i < 2000; i++) for (int j = 0; j < 10; j++)
  for(int k = 0; k < 251; k++) dp1[i][j][k] = 1000;

  for(int j = 0; j < 10; j++){
      for(int i = 0; i < 251; i++)
      dp1[0][j][i] = 0;
  }

  for(int i = 1; i <= n*5; i++){
    for(int j = 0; j < 6;j++){
      dp1[i][j][0] = dp1[i][j-1][quantity[j-1]];
      for(int k = 1; k <= quantity[j]; k++){
        if(k == 1)dp1[i][j][k] = dp1[i][j-1][quantity[j-1]];
        else dp1[i][j][k] = dp1[i][j][k-1];
        if(coins[j] <= i){
          if(k>1)dp1[i][j][k] = min(dp1[i][j][k],dp1[i-coins[j]][j][k-1]+1);
          else dp1[i][j][k] = min(dp1[i][j][k],dp1[i-coins[j]][j-1][quantity[j-1]]+1);
        }
      }
    }
  }
}

int main(){

  fillup();
  while(scanf("%d%d%d%d%d%d", quantity, quantity+1, quantity+2,
  quantity+3,quantity+4,quantity+5) && quantity[0]+quantity[1]+quantity[2]+quantity[3]+
  quantity[4]+quantity[5]){

    double val;
    scanf("%lf", &val);
    val*=100;
    n = (int)val;
    fillup2();
    int result = dp1[n][6][quantity[6]];
     for (int i=n+1; i<=n*5; i++)
         result = min(result,dp1[i][6][quantity[6]]+dp[i-n][6]);
     cout << setw(3) << result << endl;
     }
       return 0;
}
