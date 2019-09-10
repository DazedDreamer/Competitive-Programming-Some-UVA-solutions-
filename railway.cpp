#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct vec {
    double x;
    double y;
    vec operator+(vec &other) {
        vec temp;
        temp.x = x + other.x;
        temp.y = y + other.y;
        return temp;
    }
    vec operator-(vec &other) {
        vec temp;
        temp.x = x - other.x;
        temp.y = y - other.y;
        return temp;
    }

    vec operator*(double t) {
        vec temp;
        temp.x = x * t;
        temp.y = y * t;
        return temp;
    }
};

vec points[10000];

double ansx, ansy, currmax;

double dot(vec v1, vec v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

double dist(vec v1, vec v2) {
    double dx = v1.x - v2.x;
    double dy = v2.y - v1.y;
    return dx * dx + dy * dy;
}

void distance(vec v1, vec v2, vec point) {
    double dotprod = dot(point - v1, v2 - v1);
    auto tem = dotprod / dist(v1, v2);
    double t = max(0.0, min(1.0, tem));
    vec proj =(v2-v1)*t; proj = proj+v1;
    double ret = dist(point, proj);
    if(ret < currmax){
        currmax = ret;
        ansx = proj.x, ansy = proj.y;
    }
}

int main() {
    double mx,my;

    while (scanf("%lf%lf", &mx, &my) == 2) {
        currmax = numeric_limits<double>::max();
        vec point; point.x = mx, point.y = my;
        int n;
        scanf("%d", &n);
        double x,y;
        for (int i = 0; i < n+1; i++) {
            scanf("%lf%lf", &x, &y);
            points[i].x = x, points[i].y = y;
        }
        if(n==0){ printf("%.4lf\n%.4lf\n", points[0].x, points[0].y);continue;}
        for(int i = 1; i < n+1;i++){
            vec v1, v2;
            v1.x = points[i-1].x, v1.y = points[i-1].y;
            v2.x = points[i].x, v2.y = points[i].y;
            distance(v1, v2, point);
        }

        printf("%.4lf\n%.4lf\n", ansx, ansy);
    }
    return 0;
}
