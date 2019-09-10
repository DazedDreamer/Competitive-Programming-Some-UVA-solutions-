#include <cstdio>


using namespace std;

long long grid[101][101];

int main(){
  int t, rows, cols, budget;
  scanf("%d", &t);
  int cas = 0;

  while(t--){
    scanf("%d%d%d", &rows, &cols, &budget);


    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        scanf("%lld", &grid[i][j]);

        if(i > 0) grid[i][j] += grid[i-1][j];
        if(j) grid[i][j] += grid[i][j-1];
        if(i && j)grid[i][j] -= grid[i-1][j-1];
      }
    }

    long long maxarea = 0;
    long long minprice = 0;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){

        for(int i1 = i; i1<rows; i1++){
          for(int j1 = j; j1 < cols;j1++){
            // get the currprice
            long long currprice = grid[i1][j1];

            if(j > 0) currprice -= grid[i1][j-1];
            if(i > 0)currprice -= grid[i-1][j1];
            if(i && j) currprice += grid[i-1][j-1];

            // check if the price is in budget
            if(currprice <= budget){
              // get the area
              long long currarea = (i1-i+1)*(j1-j+1);
              if(currarea > maxarea){ maxarea = currarea; minprice = currprice;}
              else if (currarea == maxarea) if (currprice < minprice) minprice = currprice;
            }
          }
        }
      }
    }

    printf("Case #%d: %lld %lld\n", ++cas, maxarea, minprice);
  }
  return 0;
}
