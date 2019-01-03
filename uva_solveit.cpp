#include <cmath>
#include <cstdio>


using namespace std;

int p,q,r,s,t,u;

double f(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

double fd(double x){ // the derivative of function f
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

double newton(){
    if (f(0)==0) return 0;
    for (double x=0.5; ;){             
        double x1 = x - f(x)/fd(x);      
        if (fabs(x1-x) < 1e-7) return x;  
        x = x1;
    }
}
void bisection(){
    double lo = 0, hi = 1;

    while(lo + 1e-7< hi){
        double midpoint = (lo + hi)/2.0;

        if(f(lo) * f(midpoint) <= 0){
            hi = midpoint;
        }

        if(f(hi) * f(midpoint) <= 0){
            lo = midpoint;
        }
    }

    printf("%.4lf\n", (lo+hi)/2.0);
}


int main(){
    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF){
        if(f(0)*f(1) > 0) printf("No solution\n");
        else printf("%.4lf\n”, newton());
    }
    return 0;
}
