#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

int coins[] = {5,10,20,50,100,200};
int dp[2500][10]; // d(i,j) min coins to make i from coins[0...j-1]
int dp1[2500][10][251];
int quantity[10];
int n;

int getmin(int idx, int val, int k){
    if(val < 0) return 1000000;
    if(val == 0) return 0;
    if(idx >= 6 ){ if (val > 0) return 1000000; else return 0;}

    int currmin = 1000;
    if(dp1[val][idx][k] < 1000) return dp1[val][idx][k];

    for (int i = 1; i <= quantity[idx]; i++) {
        currmin = min(currmin, i + getmin(idx+1, val - coins[idx]*i, quantity[idx+1]));
    }

    int withoutmin = getmin(idx+1, val, quantity[idx+1]);

    return dp1[val][idx][k] = min(currmin, withoutmin);
}

void fillup(){
    for(int i =0 ;i < 2500; i++) for (int j = 0; j < 10; j++) dp[i][j] = 1000;

    // base case

    for(int i = 0; i < 10; i ++){
        dp[0][i] = 0;
    }

    // general cases
    for(int i = 1; i < 2000;i++){
        for(int j = 0; j < 6; j++){
            if(coins[j] > i) dp[i][j] = dp[i][j-1];
            else{
                dp[i][j] = min(dp[i-coins[j]][j] + 1, dp[i][j-1]);
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

        for(int i =0 ;i < 2500; i++) for (int j = 0; j < 10; j++)
            for(int k = 0; k < 251; k++) dp1[i][j][k] = 1000;


        int result = getmin(0, n, quantity[0]);
//        for (int i=n+1; i<=n*5; i++) getmin(0, i, quantity[0]);

        for (int i=n+1; i<=n*5; i++) {
            int ret = dp[i - n][5];
            int ret1 =  getmin(0, i, quantity[0]);
            result = min(result, ret1 + ret);
        }
        cout << setw(3) << result << endl;
    }
    return 0;
}
