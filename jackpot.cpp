#include <cstdio>
#include <iostream>
using namespace std;
int arr[10010];
int main(){
  int n;
  while(scanf("%d", &n) && n){
    for(int i = 0; i < n;i++){
      scanf("%d", &arr[i]);
    }
    int ans = arr[0];
    for(int i = 1; i < n;i++){
      arr[i] = max(arr[i], arr[i] + arr[i-1]);
      if(arr[i] > ans) ans = arr[i];
    }
    if(ans > 0)
    printf("The maximum winning streak is %d.\n", ans);
    else printf("Losing streak.\n");
  }
  return 0;
}
