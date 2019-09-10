#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int points[15][2]; //  first point will always be the starting idx

int getdistance(int x, int y, int a, int b){
    return (abs(x-a) + abs(y-b));
}

int n;

long long int solve(int currx, int curry, int mask){
    if(mask == pow(2.0, n+1) - 1){
        return getdistance(currx, curry, points[0][0], points[0][1]);
    }
    long long currmin = 0xffffff;
    for(int i = 0; i < n+1;i++){
        int u = mask & (1 << i);
        if(u == 0){ // not visited this city
            int dist = getdistance(currx, curry, points[i][0], points[i][1]);
            dist += solve(points[i][0], points[i][1], mask | (1 << i));

            if(dist < currmin) currmin = dist;
        }
    }

    return currmin;
}



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int sizex, sizey;
        scanf("%d%d", &sizex, &sizey);

        scanf("%d%d", &points[0][0], &points[0][1]);

        scanf("%d", &n);
        for(int i = 1; i < n+1; i++){
            scanf("%d%d", &points[i][0], &points[i][1]);
        }

        printf("The shortest path has length %lld\n", solve(points[0][0], points[0][1], 1));

    }
}
