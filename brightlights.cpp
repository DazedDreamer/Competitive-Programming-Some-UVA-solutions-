#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cfloat>
using namespace std;

struct point{
    int x,y,z;
    double slope;
};

bool cmp(const point& p1, const point& p2){
    if(p1.slope == p2.slope){
        long long c1 = (long long)p1.x*p1.x+(long long)p1.y*p1.y;
        long long c2 = (long long)p2.x*p2.x + (long long)p2.y*p2.y;
        return c1 < c2; // sort by euclidean
    } else return p1.slope < p2.slope;
}
int main(){
    int n,cas = 0;
    vector<point> points;
    while(scanf("%d", &n) && n){
        points.clear();
        int xr, yr, z;
        for(int i = 0; i < n;i++){
            scanf("%d%d%d", &xr, &yr, &z);
            point temp;
            temp.x = xr;
            temp.y = yr;
            temp.z = z;
            temp.slope = atan2(yr, xr);
            points.push_back(temp);
        }

        sort(points.begin(), points.end(), cmp);

        vector<point> answers;
        int maxh = points[0].z;
        for(int i = 1; i < n;i++){

            if(fabs(points[i].slope - points[i-1].slope) <=1e-10){
                if(points[i].z > maxh){
                    maxh = points[i].z;
                } else {
                    point temp;
                    temp.x = points[i].x, temp.y = points[i].y;
                    answers.push_back(temp);
                }

            } else {
                maxh = points[i].z;
            }
        }

        printf("Data set %d:\n", ++cas);
        if(answers.size() > 0){
            sort(answers.begin(), answers.end(), [](const point& p1, const point& p2){if(p2.x == p1.x) return p1.y < p2.y; else return p1.x < p2.x;});
            printf("Some lights are not visible:\n");
            int  i;
            for(i = 0; i < answers.size()-1; i++){
                printf("x = %d, y = %d;\n", answers[i].x, answers[i].y);
            }
            printf("x = %d, y = %d.\n", answers[i].x, answers[i].y);

        } else {
            printf("All the lights are visible.\n");
        }
    }
    return 0;
}
