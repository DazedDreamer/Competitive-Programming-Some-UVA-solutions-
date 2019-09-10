#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[100][250000], windstrengths[10][1500];
int x;

int solve(int idx, int height){
    if(idx == x/100){
        return 0;
    }

    if(dp[idx][height]!= -1) return dp[idx][height];

    // at every stage i can either climb down, up, or stay, with constraints
    int costup = -1, costdown = -1, coststay = -1;
    if(height < 9 && (x/100 - idx > idx)){
        costup = 60 - windstrengths[height][idx] + solve(idx+1, height+1);
    }

    if(height > 0){
        costdown = 20 - windstrengths[height][idx] + solve(idx+1, height-1);
    }

    if(x/100 - idx > height){
        coststay = 30 - windstrengths[height][idx] + solve(idx+1, height);
    }

    int ans = 0;
    ans = min(costup, costdown);
    if(costup < 0 || costdown <0) ans = max(costup, costdown);

    if(ans < 0 || coststay < 0) ans = max(ans, coststay);
    else ans = min(ans, coststay);

    return dp[idx][height] = ans;

}


int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        memset(dp, -1, sizeof(dp));
        scanf("%d", &x);

        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < x/100; j++){
                scanf("%d", &windstrengths[i][j]);
            }
        }

        printf("%d\n\n", solve(0,0));
    }
}
