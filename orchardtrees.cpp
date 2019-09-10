#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point {
  double x, y;
  point(){};
  point(int x, int y): x((double)x), y((double)y){}
  bool operator<(point& other){
    return x < other.x;
  }
};

double getarea(point a, point b, point c){
  double x1 = a.x, x2 = b.x, x3 = c.x;
  double y1 = a.y, y2 = b.y, y3 = c.y;

  return fabs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1)/2.0;
}

int main(){
  point points[4];
  while(true){
    double sum = 0;
    for(int i  =0 ; i < 3;i++){
      scanf("%lf%lf", &points[i].x, &points[i].y);
      sum += points[i].x + points[i].y;
    }

    if(sum == 0) return 0;
    double maxtop = -1, maxbottom = 1000, maxleft = 1000, maxright = -1;
    for(int i = 0; i < 3; i++){
      double currx = points[i].x, curry = points[i].y;
      if(currx < maxleft) maxleft = currx;
      if(currx > maxright) maxright = currx;
      if(curry < maxbottom) maxbottom = curry;
      if(curry > maxtop) maxtop = curry;
    }

    // printf("maxtop %lf, maxbottom %lf, maxleft %lf, maxright %lf\n", maxtop, maxbottom
                                      // , maxleft, maxright);
    // now we have to find our search space for the points potentially inside
    // the triangle
    int ybeg = min(99.0, floor(maxtop)), yend = max(1.0,ceil(maxbottom)); // ybeg >= y >= yend
    int xbeg = max(1.0, ceil(maxleft)), xend = min(99.0, floor(maxright));

    // printf("ybeg %d, yend %d, xend %d, xbeg %d\n", ybeg, yend, xend, xbeg);
    double area_curr_triangle = getarea(points[0], points[1], points[2]);
    // printf("area of triangle : %lf\n", area_curr_triangle);
    int ans = 0;
    for(int y = ybeg; y >= yend; y--){
      for(int x = xbeg; x <= xend; x++){
        point temp(x,y);
        double area1 = getarea(points[0], points[1], temp);
        double area2 = getarea(points[2], points[1], temp);
        double area3 = getarea(points[2], points[0], temp);
        // printf("area1 + area2 + area3 = %lf\n", area1+area2+area3);
        if(fabs(area_curr_triangle - area1 - area2 - area3) <= 1e-7) ans++;
      }
    }

    printf("%4d\n", ans);
  }
  return 0;
}
