#include <cstdio>
#include <cmath>


int main(){
  int t, cas = 0;
  scanf("%d", &t);
  while(t--){
    double r,d,h1;
    scanf("%lf%lf%lf", &r, &d, &h1);
    double ab = 2 * sqrt(pow(r,2.0) - pow(r-d, 2.0));
    double beta = asin((r-d)/r);
    double alpha = asin((r-h1)/r);
    double part1 = ab*sin(alpha - beta);
    printf("Case %d: %.4lf\n", ++cas, h1 + part1);
  }

  return 0;
}
