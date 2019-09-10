#include <cstdio>
#include <cmath>

using namespace std;


int main(){
  double xa, ya, xb, yb;
  double anglecmd, angleenf;
  double pi = acos(-1.0);
  while(scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &anglecmd, &angleenf) != EOF){
    // the height
    double height = hypot((double)xa - xb, (double)ya - yb);

    // get NA and ma
    double na = height/tan(angleenf*pi/180);
    double ma = height/tan(anglecmd*pi/180);

    // print the answer
    printf("%.3lf\n", na+ma);
  }
  return 0;
}
