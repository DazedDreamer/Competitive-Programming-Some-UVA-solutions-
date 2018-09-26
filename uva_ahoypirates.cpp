//
//  uva_ahoypirates.cpp
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
int segmenttree[1024000 << 2];
int army[1024000];


int rmq(int l, int r, int currl, int curr_r, int currnode, char *lazy) {
    int mid = curr_r + currl >> 1;
    if (lazy[currnode] != '\0') {
        char currop = lazy[currnode];
        if (currop == 'F') segmenttree[currnode] = curr_r - currl + 1;
        if (currop == 'E') segmenttree[currnode] = 0;
        if (currop == 'I') segmenttree[currnode] = curr_r - currl + 1 - segmenttree[currnode];
        
        if (currl != curr_r) {
            if (currop == 'F' || currop == 'E') lazy[currnode * 2 + 1] = lazy[currnode * 2 + 2] = currop;
            else if (currop == 'I') {
                if (lazy[currnode * 2 + 1] == 'F') lazy[currnode * 2 + 1] = 'E';
                else if (lazy[currnode * 2 + 1] == 'E') lazy[currnode * 2 + 1] = 'F';
                else if (lazy[currnode * 2 + 1] == 'I') lazy[currnode * 2 + 1] = '\0';
                else lazy[currnode * 2 + 1] = 'I';
                
                if (lazy[currnode * 2 + 2] == 'F') lazy[currnode * 2 + 2] = 'E';
                else if (lazy[currnode * 2 + 2] == 'E') lazy[currnode * 2 + 2] = 'F';
                else if (lazy[currnode * 2 + 2] == 'I') lazy[currnode * 2 + 2] = '\0';
                else lazy[currnode * 2 + 2] = 'I';
            }
        }
        lazy[currnode] = '\0';
    }
    if (l > curr_r || r < currl)return 0;
    if (l <= currl && r >= curr_r) return segmenttree[currnode];
    if (l > curr_r || r < currl) return 0;
    auto sum =
    rmq(l, r, currl, mid, (currnode << 1) + 1, lazy) + rmq(l, r, mid + 1, curr_r, (currnode << 1) + 2, lazy);
    return sum;
}

int buildtree(int l, int r, int currnode) {
    if (l == r) {
        segmenttree[currnode] = army[l];
        return army[l];
    }
    int mid = (l + r) / 2;
    segmenttree[currnode] = (buildtree(l, mid, (currnode << 1) + 1)) * (buildtree(mid + 1, r, (currnode << 1) + 2));
    return segmenttree[currnode];
}

void updaterange(int start, int end, char code, int currl, int curr_r, int currnode, char *lazy) {
    if (lazy[currnode] != '\0') {
        char currop = lazy[currnode];
        if (currop == 'F') segmenttree[currnode] = curr_r - currl + 1;
        if (currop == 'E') segmenttree[currnode] = 0;
        if (currop == 'I') segmenttree[currnode] = curr_r - currl + 1 - segmenttree[currnode];
        
        if (currl != curr_r) {
            if (currop == 'F' || currop == 'E') lazy[currnode * 2 + 1] = lazy[currnode * 2 + 2] = currop;
            else if (currop == 'I') {
                if (lazy[currnode * 2 + 1] == 'F') lazy[currnode * 2 + 1] = 'E';
                else if (lazy[currnode * 2 + 1] == 'E') lazy[currnode * 2 + 1] = 'F';
                else if (lazy[currnode * 2 + 1] == 'I') lazy[currnode * 2 + 1] = '\0';
                else lazy[currnode * 2 + 1] = 'I';
                
                if (lazy[currnode * 2 + 2] == 'F') lazy[currnode * 2 + 2] = 'E';
                else if (lazy[currnode * 2 + 2] == 'E') lazy[currnode * 2 + 2] = 'F';
                else if (lazy[currnode * 2 + 2] == 'I') lazy[currnode * 2 + 2] = '\0';
                else lazy[currnode * 2 + 2] = 'I';
            }
        }
        
        lazy[currnode] = '\0';
    }
    if (start > curr_r || end < currl)return;
    if (start <= currl && end >= curr_r) {
        if (code == 'I') segmenttree[currnode] = curr_r - currl - segmenttree[currnode] + 1;
        if (code == 'F') segmenttree[currnode] = curr_r - currl + 1;
        if (code == 'E') segmenttree[currnode] = 0;
        
        
        if (currl != curr_r) {
            if (code == 'F' || code == 'E') lazy[currnode * 2 + 1] = lazy[currnode * 2 + 2] = code;
            else if (code == 'I') {
                if (lazy[currnode * 2 + 1] == 'F') lazy[currnode * 2 + 1] = 'E';
                else if (lazy[currnode * 2 + 1] == 'E') lazy[currnode * 2 + 1] = 'F';
                else if (lazy[currnode * 2 + 1] == 'I') lazy[currnode * 2 + 1] = '\0';
                else lazy[currnode * 2 + 1] = 'I';
                
                if (lazy[currnode * 2 + 2] == 'F') lazy[currnode * 2 + 2] = 'E';
                else if (lazy[currnode * 2 + 2] == 'E') lazy[currnode * 2 + 2] = 'F';
                else if (lazy[currnode * 2 + 2] == 'I') lazy[currnode * 2 + 2] = '\0';
                else lazy[currnode * 2 + 2] = 'I';
            }
        }
        
        return;
    }
    
    int mid = curr_r + currl >> 1;
    
    updaterange(start, end, code, currl, mid, currnode * 2 + 1, lazy);
    updaterange(start, end, code, mid + 1, curr_r, currnode * 2 + 2, lazy);
    segmenttree[currnode] = segmenttree[currnode * 2 + 1] + segmenttree[currnode * 2 + 2];
}

int main() {
    
    
}
