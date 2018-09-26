//
//  uva_multitasking.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

bitset<1000001> b;

int main() {
    int n,m, start,end, rep;
    
    while(scanf("%d%d", &n, &m) && (n || m)){
        b.reset();
        bool is_good = true;
        
        for(int i = 1; i < n+1; i++){
            scanf("%d %d", &start, &end);
            if(!is_good) continue;
            
            for(int k = start; k < end; k++) {
                if (b[k]) {
                    
                    is_good = false;
                    break;
                }
                else b.set(k);
            }
        }
        
        for(int i = 1; i < m+1; i++){
            scanf("%d%d%d", &start, &end, &rep);
            if(!is_good) continue;
            
            while(is_good && end < 1000000){
                for(int j = start; j < end; j++){
                    if(b[j]){
                        is_good = false;
                        break;
                    }
                    else {
                        b.set(static_cast<size_t>(j));
                    }
                    
                    
                }
                
                start += rep;
                end = min(end+rep, 1000000);
                
            }
        }
        
        cout<< (is_good ? "NO " : "") << "CONFLICT" << endl;
    }
    
}
