#include <cstdio>
#include <cmath>
#include <vector>
double holes[110];
using namespace std;
int main(){
    int m, n;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%lf", holes+i);
    }

    scanf("%d", &n);
    double a,b,c;
    for(int i = 0; i < n;i++){
        scanf("%lf%lf%lf", &a, &b, &c);
        double s = (a+b+c)/2;
        double aa = a*a, bb = b*b, cc = c*c;
        double area = sqrt(s*(s-a)*(s-b)*(s-c));
        double diameter = 2*(a*b*c)/(4*area);
        if(aa + bb < cc) diameter = c;
        else if(aa + cc < bb) diameter = b;
        else if(bb+cc <aa)diameter = a;
        int flag = 0;
        vector<int> ans;
        for(int j = 0; j < m;j++){
            if(holes[j] >= diameter){
                flag = 1;
                ans.push_back(j+1);
            }
        }
        if(flag){
            printf("Peg %c will fit into hole(s):", i+'A');
            for(auto i : ans){
                printf(" %d", i);
            }
            printf("\n");
        } else {
            printf("Peg %c will not fit into any holes\n", i+'A');
        }
    }
}
