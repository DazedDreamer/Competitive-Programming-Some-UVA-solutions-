//
//  uva_ancientmessages.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;


string hex2bin[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void fillbackgroundw_dfs(int x, int y, int h, int w, string *grid) {
    if (x < 0 || y < 0 || x >= h || y >= w) return;
    if (grid[x][y] != '0') return;
    grid[x][y] = 'w';
    for (int i = 0; i < 4; i++) {
        fillbackgroundw_dfs(x + dx[i], y + dy[i], h, w, grid);
    }
}

void fillholewithh(int x, int y, string *grid) {
    if (grid[x][y] != '0') return;
    grid[x][y] = 'h';
    for (int i = 0; i < 4; i++) {
        fillholewithh(x + dx[i], y + dy[i], grid);
    }
}

void fillcomponentb_dfs(int x, int y, int &holes, int h, int w, string *grid) {
    if (!(x < 0 || y < 0 || x >= h || y >= w)) {
        if (grid[x][y] == '0') {
            holes++;
            fillholewithh(x, y, grid);
            return;
        }
        
        if (grid[x][y] != '1') return;
    }
    
    grid[x][y] = 'b';
    for (int i = 0; i < 4; i++) {
        fillcomponentb_dfs(x + dx[i], y + dy[i], holes, h, w, grid);
    }
}

int main() {
    int h, cas = 0;
    unsigned long w;
    while (scanf("%d%d\n", &h, &w) && w && h) {
        string grid[202];
        char line[200];
        for (int i = 0; i < h; i++) {
            grid[i + 1] += "0";
            gets(line);
            for (int j = 0; j < strlen(line); j++) {
                char c = line[j];
                if (c - '0' >= 0 && c - '0' <= 9) {
                    grid[i + 1] += hex2bin[c - '0'];
                } else {
                    grid[i + 1] += hex2bin[c - 'a' + 10];
                }
            }
            
            grid[i + 1] += "0";
        }
        
        h += 2;
        w = w * 4 + 2;
        for (int j = 0; j < w; j++) {
            grid[0] += "0";
            grid[h - 1] += "0";
        }
        
        vector<int> holesincomponents;
        fillbackgroundw_dfs(0, 0, h, w, grid);
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '1') {
                    int holes = 0;
                    fillcomponentb_dfs(i, j, holes, h, w, grid);
                    holesincomponents.push_back(holes);
                }
            }
        }
        
        cout << "Case " << ++cas << ": ";
        vector<char> ans;
        for (int i : holesincomponents) {
            if (i == 0) ans.push_back('W');
            if (i == 1) ans.push_back('A');
            if (i == 2) ans.push_back('K');
            if (i == 3) ans.push_back('J');
            if (i == 4) ans.push_back('S');
            if (i == 5) ans.push_back('D');
        }
        
        sort(ans.begin(), ans.end());
        for (char c:ans) cout << c;
        cout << endl;
    }
    return 0;
    
}
