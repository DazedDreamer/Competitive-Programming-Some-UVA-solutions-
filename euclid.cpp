#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double dist(double x, double y, double x1, double y1){
    auto dx = x - x1, dy = y - y1;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    double x_a, y_a, x_b, y_b, x_c, y_c, x_d, y_d, x_e, y_e, x_f, y_f;

    while( scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",
                 &x_a, &y_a, &x_b, &y_b, &x_c, &y_c, &x_d, &y_d, &x_e, &y_e, &x_f, &y_f)
           && (x_a + y_a+x_b+y_b+x_c+y_c+x_d+y_d+x_e+y_e+x_f+y_f)){

        // translate
        double trans_xa = 0.0, trans_ya = 0.0;
        double trans_xc = x_c - x_a, trans_yc = y_c - y_a;
        double trans_xb = x_b - x_a, trans_yb = y_b - y_a;

        // get the cross product
        double vecabx = x_b - x_a, vecaby = y_b - y_a, vecacx = x_c - x_a, vecacy = y_c - y_a;
        double cross = vecabx*vecacy - vecacx*vecaby;

        // find the angle between x axis and ab
        double angleinrad = atan2(trans_yb, trans_xb);

        if(cross > 0) angleinrad*=-1; // change with cross
        else {
            if(angleinrad < 0) angleinrad = -(180 + (angleinrad * 180/(acos(-1.0)))) * acos(-1.0)/180;
            else angleinrad = (180 - (angleinrad*180/(acos(-1.0)))) * acos(-1.0)/180;
        }

        // rotate points
        double rot_xb = cos(angleinrad)*trans_xb - sin(angleinrad)*trans_yb;
        double rot_yb = cos(angleinrad)*trans_yb + sin(angleinrad)*trans_xb;
        double rot_xc = cos(angleinrad)*trans_xc - sin(angleinrad)*trans_yc;
        double rot_yc = cos(angleinrad)*trans_yc + sin(angleinrad)*trans_xc;

        // get area of def
        double dist_ed = dist(x_d, y_d, x_e, y_e) ;
        double dist_df = dist(x_d, y_d, x_f, y_f);
        double dist_fe = dist(x_f, y_f, x_e, y_e);
        double s = dist_ed +  dist_df + dist_fe;
        s /= 2;

        // get area of def
        double area = sqrt(s * (s - dist_ed) * (s-dist_df) * (s-dist_fe));

        // get the height, aka y_g, and y_h;
        double dist_ab = dist(trans_xa, trans_ya, rot_xb, rot_yb);
        double yg, yh, xh, xg;
        yg = yh = area/dist_ab;

        xh = (yg*rot_xc)/rot_yc;

        if(cross < 0)
        xg = xh - dist_ab; // change with cross
        else
        xg = xh+dist_ab;

        // rotate back
        double newxg = cos(-angleinrad)*xg - sin(-angleinrad)*yg;
        double newyg = cos(-angleinrad)*yg + sin(-angleinrad)*xg;
        double newxh = cos(-angleinrad)*xh - sin(-angleinrad)*yh;
        double newyh = cos(-angleinrad)*yh + sin(-angleinrad)*xh;

        // translate
        double ansxg = newxg + x_a, ansyg = newyg + y_a, ansxh = newxh+x_a, ansyh = newyh + y_a;
        printf("%.3lf %.3lf %.3lf %.3lf\n", ansxg, ansyg, ansxh, ansyh);
    }

    return 0;
}
