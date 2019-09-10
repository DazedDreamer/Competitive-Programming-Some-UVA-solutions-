#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
struct point{
  double x,y;
};

double degtorad(double theta){
  return theta*(acos(-1.0)/180);
}

double getdist(point a, point b){
  return hypot(a.x - b.x, a.y - b.y);
}

point rotate(point vec, ){
  return point ({sin()  , })
}

int main(){
  int cas = 0;
  int n;
  while(scanf("%d", &n) && n){
    point p1, p2, p3;
    scanf("%lf%lf", &p1.x, &p1.y);
    scanf("%lf%lf", &p2.x, &p2.y);
    scanf("%lf%lf", &p3.x, &p3.y);
    double degree = n/360.0;
    double p1p2 = getdist(p1,p2);
    double p2p3 = getdist(p2,p3);
    double p3p1 = getdist(p3,p1);
    double s = p1p2+p2p3+p3p1;
    s/=2;
    degree = degtorad(degree);
    double area = sqrt(s*(s-p1p2)*(s-p2p3)*(s-p3p1));
    // get the circumcenter and radius
    point circumcenter;
    circumcenter.x = (p1.x+p2.x+p3.x)*sin(2*degree) / (3*sin(2*degree));
    circumcenter.y = (p1.y+p2.y+p3.y)*sin(2*degree) / (3*sin(2*degree));
    double circum_radius = (p1p2*p2p3*p3p1)/(4*area);


    point currpoint = p1;
    point vec;

    vec.x = circumcenter.x - currpoint.x;
    vec.y = circumcenter.y - currpoint.y;
    vec.x = vec.x / hypot(vec.x, vec.y);
    vec.y = vec.y / hypot(vec.x, vec.y);


    int maxy, maxx, minx, miny; maxy = maxx = -FLT_MAX;
    minx = miny = FLT_MAX;
    for(int i = 0; i < n;i++){
      // got the unit vector, now scale it by the distance
      double tempx = vec.x * circum_radius;
      double tempy = vec.y * circum_radius;

      // now update
      maxy = max(maxy, tempy); miny = min(miny, tempy);
      minx = min(minx, tempx); maxx = max(maxx, tempx);

      // now rotate


    }

  }
  return 0;
}
