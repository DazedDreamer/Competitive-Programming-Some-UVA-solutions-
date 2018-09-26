//
//  uva_thelonesomecargodistributor.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;


bool isempty(queue<int> (&p)[101], stack<int>& carrier) {
    auto clear = carrier.empty();
    for (queue<int> l: p) {
        clear &= l.empty();
    }
    
    return clear;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        stack<int> carrier;
        queue<int> qs[101];
        int time = 0, current_station = 1;
        int n, s, q;
        scanf("%d%d%d", &n, &s, &q);
        
        for (int i = 1; i < n + 1; i++) {
            int qnum, id;
            scanf("%d", &qnum);
            while (qnum--) {
                scanf("%d", &id);
                qs[i].push(id);
            }
        }
        
        while (true) {
            
            // unload and add time
            while (!carrier.empty() && (carrier.top() == current_station || qs[current_station].size() < q)) {
                int cargo = carrier.top();
                if (cargo != current_station) {
                    qs[current_station].push(cargo);
                }
                carrier.pop();
                time++;
            }
            
            // load and add time
            while (carrier.size() < s && !qs[current_station].empty()) {
                int cargo = qs[current_station].front();
                qs[current_station].pop();
                carrier.push(cargo);
                time++;
            }
            
            if(isempty(qs, carrier)) break;
            
            //change station and add time
            current_station++;
            
            if (current_station > n) {
                current_station = 1;
            }
            
            time += 2;
        }
        
        cout << time<<endl;
        //if (testcase) cout << endl;
    }
}




