//
// Created by Snehil Chopra on 6/22/18.
//

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include <list>

using namespace std;

bool already_told[2500];

int main(){
    int a,b,e;
    scanf("%d", &e);
    list<int>* adj = new list<int>[e];
    int i = 0;
    
    while(e--){
        scanf("%d", &a);
        while(a--){
            scanf("%d", &b);
            adj[i].push_back(b);
        }
        
        i++;
    }
    
    int testcase;
    scanf("%d", &testcase);
    
    while(testcase--){
        int max_boom_size = 0;
        int day = 1;
        int max_boom_size_day;
        
        vector<int> visitedatthislevel;
        
        int source;
        memset(already_told, false, sizeof(already_told));
        
        set<int> newspplthislvl;
        scanf("%d", &source);
        already_told[source] = true;
        queue<int> employees;
        queue<int> depth;
        depth.push(0);
        int depth_check = 0;
        employees.push(source);
        
        while(!employees.empty()){
            int currdepth = depth.front();
            
            if(currdepth != depth_check){
                day++;
                depth_check = currdepth;
                for (int l : visitedatthislevel) {
                    already_told[l] = true;
                }
                
                newspplthislvl.clear();
                visitedatthislevel.clear();
            }
            
            
            int curremployee = employees.front();
            employees.pop();
            depth.pop();
            
            list<int>::iterator it;
            
            for(it = adj[curremployee].begin(); it != adj[curremployee].end(); ++it){
                if(!already_told[*it]){
                    employees.push(*it);
                    visitedatthislevel.push_back(*it);
                    depth.push(currdepth + 1);
                    newspplthislvl.insert(*it);
                }
            }
            
            if(newspplthislvl.size() > max_boom_size){
                max_boom_size = static_cast<int>(newspplthislvl.size());
                max_boom_size_day = day;
            }
        }
        
        
        if(max_boom_size != 0){
            if(testcase!=0) {
                printf("%d %d\n", max_boom_size, max_boom_size_day);
            } else {
                printf("%d %d", max_boom_size, max_boom_size_day);
            }
        }
        else {
            if (testcase != 0) cout<<0<<endl;
            else cout<<0;
        }
        
    }
}
