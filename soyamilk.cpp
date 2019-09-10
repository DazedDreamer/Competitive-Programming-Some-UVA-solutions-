#include <cstdio>
#include <cmath>

using namespace std;


int main(){
  int l,w,h,theta;
  while(scanf("%d%d%d%d", &l, &w, &h, &theta) == 4){
    double pi = acos(-1.0);
    double angrad = theta * pi/180.0;

    if(tan(angrad) < (double)h/l){
      printf("%.3lf mL\n", l*w*h - l*l*tan(angrad)*0.5*w);
    } else {
      printf("%.3lf mL\n", h*h*tan(pi/2 - angrad)*0.5*w);
    }
  }
  return 0;

}
