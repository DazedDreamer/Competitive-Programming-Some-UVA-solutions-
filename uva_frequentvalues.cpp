//
//  uva_frequentvalues.cpp
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
#include <climits>
#include <unordered_map>
using namespace std;
vector<int> arr;
unordered_map<int, int> p;
int st[400004];
int freqcount[100001];

int rmq(int l, int r, int currl, int curr_r, int currnode) {
    if (l <= currl && r >= curr_r) {
        return st[currnode];
    }
    
    if(curr_r < l || currl > r) return INT_MIN;
    
    int mid = (currl + curr_r) / 2;
    int y = max(rmq(l, r, currl, mid, (currnode << 1) + 1), rmq(l, r, mid + 1, curr_r, (currnode << 1) + 2));
    return y;
}

int buildtree(int l, int r, int currnode) {
    if (l == r) {
        st[currnode] = freqcount[l];
        return freqcount[l];
    }
    int mid = (l + r) / 2;
    st[currnode] = max(buildtree(l, mid, (currnode << 1) + 1), buildtree(mid + 1, r, (currnode << 1) + 2));
    return st[currnode];
}

void preproc(int arrsize){
    for (int j = 0; j < arrsize; j++) {
        
        p[arr[j]]++;
    }
    
    for (int i = 0; i < arrsize; i++) {
        freqcount[i] = p[arr[i]];
    }
    buildtree(0, arrsize - 1, 0);
}

int maxoccurence(int arrsize, int qs, int qe) {
    int ans;
    if (arr[qs] == arr[qe]) {
        ans = qe - qs + 1;
    } else {
        int leftmost_same = 0, righmost_same = 0;
        
        while (qs > 0 && qs <= qe && arr[qs] == arr[qs - 1]) {
            qs++;
            leftmost_same++;
        }
        
        while (qe >= qs && qe < arrsize - 1 && arr[qe] == arr[qe + 1]) {
            qe--;
            righmost_same++;
        }
        // Taking maximum of all three
        int temp = rmq(qs, qe, 0, arrsize - 1, 0);
        int temp2 = max(leftmost_same, righmost_same);
        ans = max(temp, temp2);
        if(qe < qs) {
            ans = temp2;
        }
    }
    
    return ans;
}

int main() {
    int n, q;
    while (scanf("%d%d", &n, &q) == 2 && n != 0) {
        arr.clear();
        p.clear();
        memset(st, 0, sizeof(st));
        memset(freqcount, 0, sizeof(freqcount));
        int num;
        while (n--) {
            scanf("%d", &num);
            arr.push_back(num);
        }
        
        int qe, qs;
        preproc(static_cast<int>(arr.size()));
        while (q--) {
            scanf("%d%d", &qs, &qe);
            cout << maxoccurence(static_cast<int>(arr.size()), qs - 1, qe - 1) << endl;
        }
    }
}
