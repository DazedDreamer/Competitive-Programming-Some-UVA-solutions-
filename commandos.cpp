#include <cstdio>
#include <algorithm>


using namespace std;
int dist[110][110];
int t, n, r, u, v, cas = 0, s, d;

int main() {
    scanf("%d", &t);
    while (t--) {
//        if (cas)printf("\n");
        scanf("%d", &n);
        scanf("%d", &r);
        for (int i = 0; i < n + 5; i++) {
            for (int j = 0; j < n + 5; j++) {
                dist[i][j] = 0xffffff;
            }
        }

        for (int i = 0; i < r; i++) {
            scanf("%d%d", &u, &v);
            dist[u][v] = dist[v][u] = 1;
        }
        scanf("%d%d", &s, &d);

        // floyd
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j == k) dist[j][k] = 0;
                    else dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if(dist[s][i] != 0xffffff && dist[i][d] != 0xffffff)
            ans = max(ans, dist[s][i] + dist[i][d]);

        }
        printf("Case %d: %d\n", ++cas, ans);
    }
}
