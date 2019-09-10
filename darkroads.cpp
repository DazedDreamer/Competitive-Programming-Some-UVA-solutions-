#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int taken[200010];

int main(){
    int n,m;
    vector<vector<pair<int, int> > > adjlist;
    int first, second, cost;

    while(scanf("%d%d", &m, &n) &&n+m){

        adjlist.assign(m+5, vector<pair<int, int> >());
        int totalcost = 0;
        int start = -1;
        for(int i = 0; i < n;i++){

            scanf("%d%d%d", &first, &second, &cost);
            totalcost += cost;
            if(start < 0) start = first;
            taken[first] = taken[second] = 0;
            adjlist[first].push_back(make_pair(second, cost));
            adjlist[second].push_back(make_pair(first, cost));
        }

        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > q;
        int mincost = 0;
        // now push any vertex inc
        q.push(make_pair(0, start));
        // taken[start] = 1;
        while(!q.empty()){
            auto curr = q.top(); q.pop();
            int currdistance = curr.first, curridx = curr.second;
            if(!taken[curridx]) {
                mincost += currdistance;
                taken[curridx] = 1;
                for (int i = 0; i < adjlist[curridx].size(); i++) {
                    if (!taken[adjlist[curridx][i].first]) {
                        q.push(make_pair(adjlist[curridx][i].second, adjlist[curridx][i].first));
                    }
                }
            }
        }
        printf("%d\n", totalcost - mincost);

    }
}
