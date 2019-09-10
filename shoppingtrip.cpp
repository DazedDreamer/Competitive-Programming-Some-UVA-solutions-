#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <climits>
#include <map>
using namespace std;

int n,m,p;


vector<vector<int>> adjlist;
double cdcosts[56]; //  set to -1
map<int, int> maskidx;
int vis[56]; // set to 0
double dp[1 << 15][56];


double solve(int vismask, int curridx, double (&dist)[56][56]){

    if(vismask == pow(2.0, p+1) - 1){
        return  dist[curridx][0]; //  go home
    }
    if(dp[vismask][curridx] != -1) return dp[vismask][curridx];

    double currmin = FLT_MAX;
    auto it = maskidx.begin();
    for(; it != maskidx.end(); it++){
        int neighbor = (*it).first;

        int u = vismask & (1 << (maskidx[neighbor]));
        if(!u){
            double moneysaved = dist[curridx][neighbor] - cdcosts[neighbor]; // money saved compared to amazon
            moneysaved += solve(vismask | (1<< maskidx[neighbor]), neighbor, dist);
            if(moneysaved < currmin){
                currmin = moneysaved;
            }
        }
    }
    // // go home
    // double home = dist[curridx][0];
    //
    // if(home < currmin) currmin = home;

    return dp[vismask][curridx] = currmin;
}

int main(){
    int t;

    scanf("%d", &t);
    while(t--){
        double dist[56][56]; // set to maxint, records the shortest paths between two vertices
        maskidx.clear();
        memset(vis, 0, 56);
        for(int i = 0; i < 56;i++) for(int j = 0; j < 56 ;j++) dist[i][j] = FLT_MAX;
        memset(cdcosts, 0, sizeof cdcosts);
        adjlist.assign(56, vector<int>());

        scanf("%d%d", &n, &m);
        for(int i = 0;i < m;i++){
            int k,j;
            double price;
            scanf("%d%d", &k, &j);
            scanf("%lf", &price);
            adjlist[k].push_back(j);
            adjlist[j].push_back(k);
            dist[k][j] = dist[j][k] = price; // changed

        }

        // SHORTEST PATH PREPROCESSING **********************
        for (int k=0; k<n+1; k++)
            for (int i=0; i<n+1; i++)
                for (int j=0; j<n+1; j++) {
                    if(i == j) dist[i][j] = dist[j][i] = 0;
                    else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
        // ***************************

        int storenum;
        int done[15]; memset(done, 0, 15);
        int idx = 1;
        scanf("%d", &p);
        for(int i = 0; i < p;i++){
            scanf("%d", &storenum);
            if(maskidx.find(storenum) == maskidx.end()) //  if not already processed, means unique
                maskidx[storenum] = idx++;

            double cdprice;
            scanf("%lf", &cdprice);
            cdcosts[storenum]+=cdprice;
        }

        p = idx - 1;

        for(int i = 0; i < (1 << (p+1)); i++) for(int j = 0; j < 56; j++) dp[i][j] = -1;

        double ret = solve(1, 0 ,dist);
        ret = roundf(ret * 100) / 100;
        if(ret < 0)

            printf("Daniel can save $%.2lf\n", abs(ret));
        else
            printf("Don't leave the house\n");

        int k = 0; // useless
    }
}
