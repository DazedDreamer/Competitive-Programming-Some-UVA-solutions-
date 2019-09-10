#include <cstdio>
#include <algorithm>
int n,d,r;
int night[101], day[101];
int main(){
    while(scanf("%d%d%d", &n, &d, &r) && n+d+r){
        int sum = 0;

        for(int i = 0; i < n;i++){
            scanf("%d", &day[i]);

        }

        for(int i = 0; i < n;i++){
            scanf("%d", &night[i]);
        }
        std::sort(day, day+n);
        std::sort(night, night+n);

        for(int i = 0; i < n;i++){
            int temp = day[i] + night[n-i-1];
            if(temp > d){
                sum += temp - d;
            }
        }
        printf("%d\n", (sum)*r);
    }
    return 0;
}
