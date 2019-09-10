#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef double db;
struct point{
    db x,y;
};
struct lineseg{
    point p1, p2;
};
db orientation(point p, point q, point r){
    db vecpqx = q.x - p.x;
    db vecpqy = q.y - p.y;
    db vecprx = r.x - p.x;
    db vecpry = r.y - p.y;

    db cross = vecpqx*vecpry - vecprx*vecpqy;
    return cross;
}
int onsegment(point p1, point p2, point q){
    return  (q.x >= min(p1.x, p2.x) && q.x <=  max(p1.x, p2.x));
    // (q.y >= min(p1.y, p2.y) && q.y <=  max(p2.y, p1.y)) );
}

int dointersect(point p1, point p2, point q1, point q2){
    // get the four orientations
    db orip1p2q1 = orientation(p1, p2, q1);
    db orip1p2q2 = orientation(p1,p2,q2);
    db oriq1q2p1 = orientation(q1,q2,p1);
    db oriq1q2p2 = orientation(q1,q2,p2);
    if(orip1p2q1*orip1p2q2 < 0  && oriq1q2p1*oriq1q2p2<0) return true;

    // if p1 p2 q1(or q2) are collinear and q1(or q2) lies on line segment p1p2
    if(orip1p2q1 == 0 && onsegment(p1,p2,q1)) return true;
    if(orip1p2q2 == 0 && onsegment(p1,p2,q2)) return true;
    return false;
}

int main(){
    int n;
    lineseg lines[100010];
    while(scanf("%d", &n) && n){

        db x1, y1, x2,y2;
        for(int  i =0; i < n;i++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            lines[i].p1.x = x1;
            lines[i].p1.y = y1;
            lines[i].p2.x = x2;
            lines[i].p2.y = y2;

        }

        vector<int> ans;
        for(int i = 0; i < n-1;i++){
            int flag = 0;
            for(int j = i+1; j < n && !flag; j++) {
                if (dointersect(lines[i].p1, lines[i].p2, lines[j].p1, lines[j].p2)) {
                    flag = 1;
                }
            }
            if(!flag) ans.push_back(i+1);
        }

        ans.push_back(n);

        printf("Top sticks: %d", ans[0]);
        for(int i = 1; i < ans.size(); i++){
            printf(", %d", ans[i]);
        }

        printf(".\n");

    }
    return 0;
}
