#include <cstdio>

int main(){
    double a,b,c;
    int cas = 0;
    while (scanf("%lf%lf%lf", &a,&b,&c) && a >= 0)
    {
        printf("Set %d:\n", ++cas);
        if (b*b <= a*c)  printf("Poor King!\n");
        else{
            double d = a*c*(a + 2*b + c)/(b*b - a*c);
            printf("%.4lf\n", d);
        }
    }

    return 0;
}
