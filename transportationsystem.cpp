#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> point;

double getdistance(point first, point second){
    double i = pow(first.first - second.first, 2.0);
    double j = pow(first.second - second.second, 2.0);
    return pow(i+j, 0.5);
}

int main(){
    int taken[1050], cas = 0;
    vector<point> points;
    int t;
    scanf("%d", &t);
    while(t--){
        int n, r;
        int states = 1;
        double roads = 0, railroads = 0;
        points.clear();
        scanf("%d%d", &n, &r);
        for(int i = 0; i < n; i++){
            int x, y;
            taken[i] = 0;
            scanf("%d%d", &x, &y);
            points.push_back(make_pair(x,y));
        }

        priority_queue< pair<double, point>, vector<pair<double, point>>, greater<pair<double, point>>> q;

        // now compute the distances between each pair of points
        for(int i = 0; i < n;i++){
            if(i > 0) {
                double distance = getdistance(points[0], points[i]);
                q.push(make_pair(distance, make_pair(0, i)));
            }
        }

        // now check each edge one by one
        while(!q.empty()){
            auto curr = q.top(); q.pop();
            double currdistance = curr.first;
            int firstidx = curr.second.first, secondidx = curr.second.second;

            if(!taken[firstidx] || !taken[secondidx]){ // if one of them is not yet discovered
                // if distance greter than r then we have a new railroad/state
                if(currdistance > r){states += 1; railroads+=currdistance;}
                else roads += currdistance;
                int idxtopush = !taken[secondidx]?secondidx:firstidx;

                for(int i = 0; i < n;i++){
                    if(i != idxtopush && !taken[i]) {
                        double distance = getdistance(points[idxtopush], points[i]);
                        q.push(make_pair(distance, make_pair(idxtopush, i)));
                    }
                }

                // now mark both as taken to avoid cycles
                taken[firstidx] = taken[secondidx] = 1;
            }
        }
        printf("Case #%d: %d %d %d\n", ++cas, states, (int)round(roads), (int)round(railroads));

    }
}
