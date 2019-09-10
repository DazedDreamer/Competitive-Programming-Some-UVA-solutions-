#include <cmath>
#include <cstdio>
using namespace std;


int main(){
  int a,b,c;
  while(scanf("%d%d%d", &a, &b, &c) == 3){
    double s = (a+b+(double)c)/2;
    double areaoftriangle = sqrt(s * (s-a)*(s-b)*(s-c));
    double areaoutercircle = acos(-1.0) * pow((a*b*c)/(4*areaoftriangle),2.0);
    double areaofinnercircle = acos(-1.0) * pow(areaoftriangle/s, 2.0);
    double sunflowers = areaoutercircle - areaoftriangle;
    double violets = areaoftriangle - areaofinnercircle;
    double roses = areaofinnercircle;
    printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);

  }
  return 0;
}
