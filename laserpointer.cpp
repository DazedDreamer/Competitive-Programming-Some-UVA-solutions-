#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int t;
    double pi = acos(-1);
    double l, w, theta;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf%lf%lf", &l, &w, &theta);
        theta = theta/180*pi;
        double a, b;
        a = l/cos(theta);
        b = a*sin(theta);
        int times = (int)(b/w);
        b = fmod(b, w);
        if(times&1)
            b = w-b;
        b = sqrt(b*b+l*l);
        printf("%.3lf\n", a/b);
    }
    return 0;
}
