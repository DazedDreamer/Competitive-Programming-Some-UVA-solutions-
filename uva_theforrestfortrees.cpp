//
//  uva_theforrestfortrees.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

bool v[26];

void dfs(vector<int> (&destinations)[26], int i) {
    v[i] = true;
    for (int iter = 0; iter < destinations[i].size(); iter++) {
        if (!v[destinations[i][iter]]) {
            dfs(destinations, destinations[i][iter]);
        }
    }
}


int main() {
    int testcase;
    scanf("%d", &testcase);
    getchar();
    while (testcase--) {
        memset(v, false, sizeof(v));
        char s[61];
        vector<int> destinations[26];
        char edge1, edge2;
        
        while (gets(s) && s[0] != '*') {
            sscanf(s, "(%c,%c)", &edge1, &edge2);
            destinations[edge1 - 'A'].push_back(edge2 - 'A');
            destinations[edge2 - 'A'].push_back(edge1 - 'A');
        }
        memset(s, '\0', sizeof(s));
        gets(s);
        char nodes[27];
        memset(nodes, '\0', sizeof(nodes));
        
        for (int i = 0; s[i]; i += 2) {
            nodes[s[i] - 'A'] = s[i];
        }
        
        int treecount = 0, acorncount = 0;
        for (int i = 0; i < 27; i++) {
            if (nodes[i] && !v[nodes[i] - 'A']) {
                if (destinations[nodes[i] - 'A'].empty()) acorncount++;
                else {
                    dfs(destinations, nodes[i] - 'A');
                    treecount++;
                }
            }
        }
        
        printf("There are %d tree(s) and %d acorn(s).\n", treecount, acorncount);
        
    }
    
    return 0;
}
