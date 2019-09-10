#include <cstdio>
#include <iostream>

using namespace std;


int lisweights[10000], heights[10000], ldsweights[10000];

int main(){
  int t, cas = 0;
  scanf("%d", &t);
  while(t--){
    int num;
    scanf("%d", &num);

    for(int i = 0; i< num; i++){
      scanf("%d", &heights[i]);

    }

    for(int i = 0;  i< num; i++){
      scanf("%d", &lisweights[i]);
      ldsweights[i] = lisweights[i];
    }

    int longestincreasing = lisweights[0];

    for(int i = 1; i < num; i++){
      int original_weight = lisweights[i];
      for(int j = 0; j < i; j++){

        if(heights[j] < heights[i]) lisweights[i] = max(lisweights[i], lisweights[j] + original_weight);
      }

      longestincreasing = max(longestincreasing, lisweights[i]);
      // printf("lisweights[i] : %d , longestincreasing : %d\n", lisweights[i], longestincreasing);
    }

    int longestdecreasing = ldsweights[num - 1];
    for(int i = num-1; i >= 0 ; i--){
      int original_weight = ldsweights[i];

      for(int j = i + 1; j < num; j++){
        if(heights[i] > heights[j]) ldsweights[i] = max(ldsweights[i], ldsweights[j] + original_weight);
      }

      longestdecreasing = max(longestdecreasing, ldsweights[i]);
    }

    if(longestdecreasing > longestincreasing)
    printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++cas, longestdecreasing, longestincreasing);
    else
    printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++cas, longestincreasing, longestdecreasing);

  }
}
