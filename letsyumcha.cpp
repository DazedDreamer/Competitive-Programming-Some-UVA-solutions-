#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


int n,k,t,x;
int dp[150][1005][100];
int prices[110], favor[110];

int  solve(int numdishes, int idx, int moneyspent){
    double currsum = moneyspent + t*(n+1);
    double servicecharge = ceil(currsum*0.1);
    currsum += servicecharge;

    // if price or numdishes exceed

    if(currsum > (n+1)*x || (numdishes) > 2*(n+1)) return INT_MIN; // discard
    if(idx >= k) return 0;

    // all conditions are met, so now recurse
    if(dp[numdishes][moneyspent][idx] != -1) return dp[numdishes][moneyspent][idx];

    int ret = max(favor[idx] + solve(numdishes + 1, idx + 1, moneyspent + prices[idx]*1) ,
                                                max(solve(numdishes, idx + 1, moneyspent),
                                                    2*favor[idx] + solve(numdishes+2, idx+1, moneyspent + prices[idx]*2)) );

    return dp[numdishes][moneyspent][idx] = ret;

}

int main(){

    while(scanf("%d%d%d%d", &n, &x, &t, &k) && n+t+x+k){
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < k; i++){
            int currfavor, sumfav = 0;
            scanf("%d", &prices[i]);

            for(int j = 0; j < n+1; j++){
                scanf("%d", &currfavor);
                sumfav += currfavor;
            }

            favor[i] = sumfav;
        }

        printf("%.2lf\n", (double)solve(0,0,0)/(n+1));


    }

    return 0;
}
