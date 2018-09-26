//
//  uva_intervalproduct.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;


char rq(int l, int r, int currl, int curr_r, int currnode, char *segmenttree) {
    int mid = curr_r + currl >> 1;
    if (l > curr_r || r < currl) return '\0' ;
    if (l <= currl && r >= curr_r) return segmenttree[currnode];
    char lt = rmq(l, r, currl, mid, currnode * 2 + 1, segmenttree);
    char rt = rmq(l, r, mid + 1, curr_r, currnode * 2 + 2, segmenttree);
    if (lt == '0' || rt == '0') return '0';
    if (lt == '-' && rt == '-') return '+';
    if (lt == '-' || rt == '-') return '-';
    return '+';
}

void buildtree(int l, int r, int currnode, char *segmenttree, int *arr) {
    if (l == r) {
        if (arr[l] > 0){
            segmenttree[currnode] = '+';
        }
        if (arr[l] == 0){
            segmenttree[currnode] = '0';
        }
        if (arr[l] < 0) {
            segmenttree[currnode] = '-';
        }
        return;
    }
    int mid = (l + r) / 2;
    buildtree(l, mid, (currnode << 1) + 1, segmenttree, arr);
    buildtree(mid + 1, r, (currnode << 1) + 2, segmenttree, arr);
    if (segmenttree[currnode * 2 + 1] == '0' || segmenttree[currnode * 2 + 2] == '0') segmenttree[currnode] = '0';
    else if (segmenttree[currnode * 2 + 1] == '-' && segmenttree[currnode * 2 + 2] == '-') segmenttree[currnode] = '+';
    else if (segmenttree[currnode * 2 + 1] == '-' || segmenttree[currnode * 2 + 2] == '-') segmenttree[currnode] = '-';
    else segmenttree[currnode] = '+';
}

void updaterange(int start, int end, int currl, int curr_r, int currnode, int value, char *segmenttree) {
    // If out of bounds
    if (start > curr_r || end < currl)return;
    
    // If in range
    if (start <= currl && end >= curr_r) {
        if (value < 0) {
            segmenttree[currnode] = '-';
        } else if (value == 0) {
            segmenttree[currnode] = '0';
        } else {
            segmenttree[currnode] = '+';
        }
        return;
    }
    
    int mid = curr_r + currl >> 1;
    updaterange(start, end, currl, mid, currnode * 2 + 1, value, segmenttree);
    updaterange(start, end, mid + 1, curr_r, currnode * 2 + 2, value, segmenttree);
    if (segmenttree[currnode * 2 + 1] == '0' || segmenttree[currnode * 2 + 2] == '0') segmenttree[currnode] = '0';
    else if (segmenttree[currnode * 2 + 1] == '-' && segmenttree[currnode * 2 + 2] == '-')
        segmenttree[currnode] = '+';
    else if (segmenttree[currnode * 2 + 1] == '-' || segmenttree[currnode * 2 + 2] == '-')
        segmenttree[currnode] = '-';
    else segmenttree[currnode] = '+';
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        int arr[n], num;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            arr[i] = num;
        }
        char st[n << 2];
        char lazy[n << 2];
        memset(lazy, '\0', sizeof(lazy));
        memset(st, '\0', sizeof(st));
        buildtree(0, n - 1, 0, st, arr);
        getchar();
        while (k--) {
            char c;
            int i, j;
            scanf("%c %d %d", &c, &i, &j);
            getchar();
            if (c == 'C') {
                updaterange(i - 1, i - 1, 0, n - 1, 0, j, st);
            } else {
                cout << rq(i-1, j-1, 0, n - 1, 0, st);
            }
        }
        cout << endl;
    }
    return 0;
    
}

