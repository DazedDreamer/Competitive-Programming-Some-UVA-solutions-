//
//  uva_ferryloading4.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(void) {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        int ans = 0,length,l,m;
        char s[6];
        string current_side = "left";
        queue<pair<int, string>> lq,rq;
        scanf("%d%d", &length, &m);
        length = length * 100;
        while(m--){
            scanf("%d %s", &l, s);
            string temp = s;
            if (temp == "left"){
                lq.push(make_pair(l,s));
            } else {
                rq.push(make_pair(l, s));
            }
        }
        
        
        while(!lq.empty() || !rq.empty()){
            if(current_side == "left"){
                if(!lq.empty()){
                    int cap = 0;
                    while(!lq.empty() && (cap + lq.front().first) <= length){
                        cap += lq.front().first;
                        lq.pop();
                    }
                }
            } else {
                if(!rq.empty()){
                    int cap = 0;
                    while(!rq.empty() && (cap + rq.front().first) <= length){
                        cap += rq.front().first;
                        rq.pop();
                    }
                }
            }
            
            current_side = (current_side == "left") ? "right" : "left";
            ++ans;
        }
        
        cout<<ans<<endl;
    }
}


