#include <cstdio>
#include <iostream>
#include <set>
#include <climits>
using namespace std;
int dist[110][110];

int main(){
  int first, second, cas = 0;
  while(true){
    scanf("%d%d", &first, &second);
    set<int> elems;
    if(!(first+second)){
      break;
    } else {
      for(int i = 0; i <110;i++) for(int j = 0; j < 110;j++)dist[i][j] = 1000;
      dist[first][second] = 1;
      elems.insert(first);elems.insert(second);
    }
    while(scanf("%d%d", &first, &second) && first+second){
      dist[first][second] = 1;
      elems.insert(first);elems.insert(second);
    }

    int n = *(elems.rbegin());
    printf("n  = %d\n", n);
    for(int i = 1; i < n+1; i++){
      for(int j = 1; j < n+1; j++){
        for(int k = 1; k < n+1; k++){
          if(j == k) dist[j][k] = 0;
          else{
             dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
          }
        }
      }
    }
    int sum = 0;
    for(auto e: elems){
      for(int i = 1; i <= n; i++){
        if(e != i && dist[e][i] < 1000 ) sum += dist[e][i];
      }
    }

    printf("Case %d: average length between pages = %.3lf clicks\n", ++cas, (sum / (double)(elems.size() * (elems.size()-1)) ));

  }

}
