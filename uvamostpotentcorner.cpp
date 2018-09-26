//
//  uvamostpotentcorner.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

inline bool neighbors(int i, int j) {
    int n = i^j;
    return (n&(-n)) == n;
}

int n, m, potencies[1<<15];
int main() {
    
    
    while(cin >> n) {
        fill_n(potencies, 1<<n, 0);
        m = 0;
        for(int i=0; i<(1<<n); i++) {
            int x;
            cin >> x;
            for(int j=0; j<(1<<n); j++) {
                if(neighbors(i, j) && i != j) potencies[j]+=x;
            }
        }
        for(int i=0; i<(1<<n); i++) {
            for(int j=0; j<(1<<n); j++) {
                if(!neighbors(i, j) || i == j) continue;
                m = max(m, potencies[i]+potencies[j]);
            }
        }
        cout << m << '\n';
    }
    
    return 0;
}
