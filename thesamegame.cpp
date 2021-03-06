
#include <stdio.h>
#include <string.h>
int used[20][20];
int combo;
void dfs(int x, int y, char c, char (&grid)[20][20]) {
    if(x < 0 || y < 0 || x >= 10 || y >= 15)
        return ;
    if(used[x][y] || grid[x][y] != c)
        return ;
    used[x][y] = 1;
    combo++;
    dfs(x+1, y, c, grid);
    dfs(x-1, y, c, grid);
    dfs(x, y+1, c, grid);
    dfs(x, y-1, c, grid);
}
void touch(int x, int y, char c ,char (&grid)[20][20]) {
    if(x < 0 || y < 0 || x >= 10 || y >= 15)
        return ;
    if(grid[x][y] != c)
        return ;
    grid[x][y] = 0;
    combo++;
    touch(x+1, y, c, grid);
    touch(x-1, y, c, grid);
    touch(x, y+1, c, grid);
    touch(x, y-1, c, grid);
}
void F5(char (&g)[20][20]) {
    int i, j, k;
    for(i = 0; i < 15; i++) {
        int idx = 0;
        for(j = 0; j < 10; j++) {
            if(g[j][i]) {
                g[idx++][i] = g[j][i];
            }
        }
        while(idx < 10)
            g[idx][i] = 0, idx++;
    }
    k = 0;
    for(j = 0; j < 15; j++) {
        for(i = 0; i < 10; i++) {
            if(g[i][j])
                break;
        }
        if(i != 10) {//has shift right
            for(i = 0; i < 10; i++)
                g[i][k] = g[i][j];
            k++;
        }
    }
    while(k < 15) {
        for(i = 0; i < 10; i++)
            g[i][k] = 0;
        k++;
    }
}
int main() {
    char g[20][20];

    int testcase, cases = 0;
    int i, j, k;
    scanf("%d", &testcase);
    while(testcase--) {
        for(i = 9; i >= 0; i--)
            scanf("%s", &g[i]);
        memset(used, 0, sizeof(used));
        int step = 0, remaind = 150;
        int score = 0;
        printf("Game %d:\n\n", ++cases);
        while(true) {
            memset(used, 0, sizeof(used));
            int mxchoose = -1, x, y;
            for(j = 0; j < 15; j++) {
                for(i = 0; i < 10; i++) {
                    if(used[i][j] == 0 && g[i][j] != 0) {
                        combo = 0;
                        dfs(i, j, g[i][j], g);
                        if(combo >= 2) {
                            if(combo > mxchoose)
                                mxchoose = combo, x = i, y = j;
                        }
                    }
                }
            }
            if(mxchoose < 0)
                break;
            remaind -= mxchoose;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
                   ++step, x+1, y+1, mxchoose, g[x][y], (mxchoose-2)*(mxchoose-2));
            score += (mxchoose-2)*(mxchoose-2);
            touch(x, y, g[x][y], g);
            F5(g);
        }
        if(remaind == 0)
            score += 1000;
        printf("Final score: %d, with %d balls remaining.\n", score, remaind);
        if(testcase)
            puts("");
    }
    return 0;
}
