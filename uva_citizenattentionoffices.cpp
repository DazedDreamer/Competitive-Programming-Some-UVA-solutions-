#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int grid[5][5];
int ans[5], pos[5];
int minval;
void print(int idx, int i){
    if(idx == 5){
        int sum = 0;
        int i , j, k, t;
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5;j++){
                if(grid[i][j]) {
                    t = INT_MAX;
                    for (k = 0; k < 5; k++) {
                        int x = pos[k] / 5;
                        int y = pos[k] % 5;
                        if(abs(x - i) + abs(y - j) < t)t=abs(x-i) + abs(y-j);
                    }
                    
                    sum+=grid[i][j]*t;
                }
            }
        }
        
        if(sum < minval){
            minval = sum;
            for( i = 0; i < 5;i++){
                ans[i] = pos[i];
            }
        }
        
        return;
    }
    for(; i < 25;i++){
        pos[idx] = i;
        print(idx + 1, i + 1);
    }
}

int main() {
    int t, n, i, j, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(grid, 0, sizeof(grid));
        while(n--) {
            scanf("%d %d %d", &i, &j, &k);
            grid[i][j] += k;
        }
        minval = INT_MAX;
        print(0, 0);
        for(i = 0; i < 5; i++) {
            if(i)
                putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
