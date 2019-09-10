#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct point{
  int x,y;
};


point pts[110];

bool  cmp(const point& p1, const point& p2){
  return p1.x > p2.x;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    memset(pts, 0, sizeof pts);
    int n;
    scanf("%d", &n);
    int x,y;
    for(int i = 0; i < n; i++){
      scanf("%d%d", &x, &y);
      pts[i].x = x, pts[i].y = y;
    }
    sort(pts, pts+n, cmp);
    // printf("pts[1].y = %d\n", pts[1].y);

    int maxh = 0; double ans = 0;
    for(int i = 1; i < n ;i++){

      int currx = pts[i].x, curry  = pts[i].y;

      if(curry > maxh){
        int prevx = pts[i-1].x, prevy  = pts[i-1].y;
        int dx = currx-prevx, dy = curry - prevy;
        double euc_to_prev = sqrt( dx*dx + dy*dy);
        double euc_to_ans = ((double)curry - maxh)*euc_to_prev/dy;
        ans += euc_to_ans;
        maxh = curry;
      }
    }

    printf("%.2lf\n", ans);
  }
  return 0;
}
