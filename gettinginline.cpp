#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cfloat>
#include <tuple>
using namespace std;


int n;
double dist[8][8];
pair<int, int> path[10][1<<8];

double solve(int curr, int vis_mask) {
    if (vis_mask == pow(2.0, n) - 1) {
        return 0;
    }

    double currmin = FLT_MAX;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        int u = vis_mask & (1 << i);
        if (u == 0) { //  not visited
            double ret = dist[curr][i] + solve(i, vis_mask | (1 << i));
            if (ret < currmin) {
                currmin = ret;

                idx = i;
            }
        }
    }

    path[curr][vis_mask] = make_pair(idx, vis_mask | (1 << idx));

    return currmin;
}


int main() {
    vector<pair<int, int>> sol;

    int cas = 0;
    while (scanf("%d", &n) && n) {
        int f, g;
        int coords[8][2];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &coords[i][0], &coords[i][1]);

        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double distance = pow(coords[i][0] - coords[j][0], 2) + pow(coords[i][1] - coords[j][1], 2);
                distance = pow(distance, 0.5);
                dist[i][j] = distance + 16;
            }
        }


        double ans = FLT_MAX;
        int ansidx = -1;
        for(int i = 0; i < n; i++){
            double temp = solve(i, (1 << i));
            if(temp < ans){
                ans = temp;
                ansidx = i;
            }
        }

        solve(ansidx, 1 << ansidx);
        printf("**********************************************************\n"
               "Network #%d\n", ++cas);

        int firstidx = ansidx, firstmask = 1 << ansidx;
        n-=1;
        for(; n; n--){

            int secondidx = path[firstidx][firstmask].first;
            int fxpos = coords[firstidx][0], fypos = coords[firstidx][1];
            int sxpos = coords[secondidx][0], sypos = coords[secondidx][1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", fxpos, fypos, sxpos, sypos, dist[firstidx][secondidx]);
            firstmask = path[firstidx][firstmask].second;
            firstidx = secondidx;

        }

        printf("Number of feet of cable required is %.2lf.\n", ans);
    }

}
