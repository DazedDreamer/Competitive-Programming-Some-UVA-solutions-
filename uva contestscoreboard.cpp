
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <tuple>


using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    if(get<0>(a) > get<0>(b)) return true;
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) < get<1>(b)) return true;
        else if(get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b)) return true;
    }
    
    return false;
}

int main() {
    int testcase;
    
    char s[101];
    gets(s);
    sscanf(s,"%d", &testcase);
    gets(s);
    
    while (testcase--) {
        
        int ptime[101][10], c, p, time;
        set<int> has_submitted;
        set<int> problems[101];
        bool solved[101][11];
        
        memset(solved, false, sizeof(solved));
        memset(ptime, 0, sizeof(ptime));
        
        char L;
        
        while (gets(s) && s[0]) {
            sscanf(s, "%d %d %d %c", &c, &p, &time, &L);
            has_submitted.insert(c);
            
            if (L == 'I' && !solved[c][p]) {
                ptime[c][p] += 20;
            } else if (L == 'C' && !solved[c][p]) {
                solved[c][p] = true;
                problems[c].insert(p);
                ptime[c][p] += time;
            } else {
                continue;
            }
        }
        
        vector<tuple<int, int, int>> ans;
        
        for (int i: has_submitted) {
            int penaltime = 0;
            for (int j = 1; j < 10; j++) {
                if (solved[i][j]) {
                    penaltime += ptime[i][j];
                }
            }
            
            ans.push_back(make_tuple(problems[i].size(), penaltime, i));
            
        }
        
        sort(ans.begin(), ans.end(), cmp);
        
        for(tuple<int, int, int> k: ans){
            cout<<get<2>(k)<<" "<<get<0>(k)<<" "<<get<1>(k)<<endl;
        }
        
        cout << endl;
        
    }
}
