#include <cstdio>
#include <climits>
int arr[100][100];

int main(){
  int n;
  scanf("%d", &n);

  for(int  i  = 0; i < n;i++){
    for(int j = 0; j < n; j++){

            scanf("%d", &arr[i][j]);

            // memoize

            if(i > 0) arr[i][j] += arr[i-1][j];
            if(j > 0) arr[i][j] += arr[i][j-1];

            if(i && j) arr[i][j] -= arr[i-1][j-1];
    }
  }

  long long max = LLONG_MIN;

  // pick a starting corner
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){


      // now pick an ending corner, both dimensions should be greater than their corresponding
      // starting dimension
      for(int i1 = i; i1 < n ;i1++){
        for(int j1 = j; j1 < n;j1++ ){
          int temp = arr[i1][j1];
          if(!i && !j){ if(max < temp) max = temp; continue;}

          if(i > 0) temp -= arr[i-1][j1];
          if(j > 0) temp -= arr[i1][j - 1];

          if(i && j) temp += arr[i-1][j-1];

          if(max < temp) max = temp;
        }
      }
    }
  }

  printf("%d\n", max);


}
