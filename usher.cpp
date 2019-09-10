#include <cstdio>
#include <algorithm>

using namespace std;
long long dist[510][510];

int main(){
  int t, n, p;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &p);
    int capacity = n;
    for(int i = 0; i < p+3; i++) for(int j = 0; j < p+3; j++)dist[i][j] = 0xffffff;

    int num, parish;
    scanf("%d", &num);
    while(num--){
      scanf("%d", &parish);
      dist[0][parish] = -1;
    }

    for(int i = 1; i < p+1; i++){
      int c, neigh, distance;
      scanf("%d", &c);
      while(c--){
        scanf("%d%d", &distance, &neigh);
        dist[i][neigh] = min(dist[i][neigh], distance);
      }
    }

    // floyd warshall
    for(int k = 0; k < p+1; k++){
      for(int i = 0; i < p+1; i++){
        for(int j = 0; j < p+1; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int mindistance = dist[0][0];
    int currsum = 0;
    int ans = 0;
    while(true){
      if(currsum + 1 + mindistance >= capacity) break;
      ans++;
      currsum += mindistance;
    }
    printf("%d\n", ans);
  }
  scanf("%d\n", &t);

  return 0;

}
