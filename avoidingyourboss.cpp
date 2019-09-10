#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int P, R, BH, OF, YH, M;
    int i, j, k, x, y, v;
    while(scanf("%d %d %d", &P, &R, &BH) == 3) {
        scanf("%d %d %d", &OF, &YH, &M);
        int g1[105][105], g2[105][105];
        for(i = 0; i <= P; i++) {
            for(j = 0; j <= P; j++)
                g1[i][j] = g2[i][j] = 1e9;
            g1[i][i] = g2[i][i] = 0;
        }
        while(R--) {
            scanf("%d %d %d", &x, &y, &v);
            g1[x][y] = g1[y][x] = v;
            g2[x][y] = g2[y][x] = v;
        }
        for(k = 1; k <= P; k++)
            for(i = 1; i <= P; i++)
                for(j = 1; j <= P; j++)
                    g1[i][j] = min(g1[i][j], g1[i][k]+g1[k][j]);
        int ban[105] = {};
        for(k = 1; k <= P; k++)
            if(g1[BH][OF] == g1[BH][k] + g1[k][OF])
                ban[k] = 1;
        for(k = 1; k <= P; k++) {
            if(ban[k] == 0)
            for(i = 1; i <= P; i++) {
                if(ban[i] == 0)
                for(j = 1; j <= P; j++) {
                    if(ban[j] == 0)
                        g2[i][j] = min(g2[i][j], g2[i][k]+g2[k][j]);
                }
            }
        }
        if(g2[YH][M] != 1e9 && ban[YH] == 0 && ban[M] == 0)
            printf("%d\n", g2[YH][M]);
        else
            puts("MISSION IMPOSSIBLE.");
    }
    return 0;
}
