#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <numeric>
#include <climits>

using namespace std;

int dist[105];
bool splset[105];

int main() {
    int t;
    
    scanf("%d", &t);
    while(t--){
        vector<pair<int, int>> destinations[105];
        int numofcells, exitcell, countdowntime, connections, src, dest, time;
        scanf("%d%d%d%d", & numofcells, &exitcell, &countdowntime, &connections);
        while(connections--){
            scanf("%d%d%d", &src, &dest, &time);
            destinations[dest].push_back(make_pair(src, time));
        }
        
        memset(dist, 1000000, sizeof(dist));
        memset(splset, false, sizeof(splset));
        
        dist[exitcell] = 0;
        int count = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int> >> q;
        q.push(make_pair(0, exitcell));
        
        while(!q.empty()){
            pair<int, int> p= q.top();
            int cell = p.second;
            q.pop();
            splset[cell] = true;
            
            for(int j = 0; j < destinations[cell].size(); j++){
                int po = destinations[cell][j].first;
                int weight =destinations[cell][j].second;
                
                if(dist[po] > dist[cell] + weight && !splset[po]){
                    dist[po] = dist[cell] + weight;
                    q.push(make_pair(dist[po],po));
                }
            }
        }
        
        
        for(int iu: dist){
            if(iu <= countdowntime){
                count++;
            }
        }
        
        if(t!=0) printf("%d\n\n", count);
        else cout<<count<<"\n";
        
        //priority_queue<pair<int, Edge>, vector<pair<int, Edge>>, greater<pair<int, Edge>>> min;
        //min.push(make_pair(dist[1], edges[1]));
    }
}

