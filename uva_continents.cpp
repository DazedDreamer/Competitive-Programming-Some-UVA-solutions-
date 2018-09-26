//
//  uva_continents.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char land;

void dfs(int x, int y, string *grid, int m, int n, int &regions) {
    if(y < 0) y = n-1;
    if(y >= n) y = 0;
    if ( x < 0 || x >= n) return;
    if(grid[x][y] != land) return;
    grid[x][y] = (char)(land + 15);
    regions++;
    for(int i = 0; i < 4; i++){
        dfs(x+dx[i], y+dy[i], grid, m, n, regions);
    }
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        string grid[m];
        for (int i = 0; i < m; i++) {
            char temp[n];
            scanf("%s", temp);
            grid[i] = temp;
        }
        
        int kx, ky;
        set<int> sizes;
        scanf("%d%d", &kx, &ky);
        int regions = 0;
        land  = grid[kx][ky];
        dfs(kx, ky, grid, m, n, regions);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == land){
                    regions = 0;
                    dfs(i,j,grid,m,n,regions);
                    sizes.insert(regions);
                }
            }
        }
        
        if(sizes.empty()) cout<<0<<endl;
        else {
            auto it = sizes.end();
            it--;
            cout << *it << endl;
        }
    }
    return 0;
    
}
