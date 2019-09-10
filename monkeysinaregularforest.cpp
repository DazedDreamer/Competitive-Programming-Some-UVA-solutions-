#include <cstdio>
#include <cstring>


using namespace std;
int rows, cols;
char grid[800][800];
int grid2[800][800];
void solve(int currx, int curry, char tomatch, int changeto){
  if(currx < 0 || currx >= cols || curry < 0 || curry >= rows || grid[curry][currx] == 0) return;
  if(grid[curry][currx] != tomatch) return;
  grid[curry][currx] = 0;
  grid2[curry][currx] = changeto;
  solve(currx+1, curry, tomatch, changeto);
  solve(currx-1, curry, tomatch, changeto);
  solve(currx, curry+1, tomatch, changeto);
  solve(currx, curry-1, tomatch, changeto);
  solve(currx+1, curry+1, tomatch, changeto);
  solve(currx+1, curry-1, tomatch, changeto);
  solve(currx-1, curry+1, tomatch, changeto);
  solve(currx-1, curry-1, tomatch, changeto);
}

int main(){
  int idx = 0;
  for(int i = 0; i < 800; i++)for(int j = 0; j < 800; j++) {grid[i][j] = 0;grid2[i][j]=0;}

  while(true){
      rows = 0, cols = 0;
      int isdone = 0;
      // read grid
      while(true){
          int i;
          for(i= 0;;){

            int ret = scanf("%c", temp);
            if(ret != 1){isdone = 1; break;}
            if(temp == '%'){getchar();break;}
            if(temp == '\n') break;
            if(temp!=' ')grid[rows][i++] = temp;
          }
          cols =max(i,cols);
          rows++;
      }
      rows--;
      cols--;

      // one test case, process now
      int currfam = 1;
      for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols; j++){
          if(grid[i][j] != 0){
            solve(i,j,grid[i][j],currfam++);
          }
        }
      }
      // print the matrix;
      for(int i = 0; i < rows; i++){
        printf("%d", grid2[i][0]);
        for(int j = 1; j < cols; j++){
          printf(" %d", grid2[i][j]);
        }
        printf("\n");
    }

    idx = 0;
    for(int i = 0; i < 800; i++)for(int j = 0; j < 800; j++) {grid[i][j] = 0;grid2[i][j]=0;}
  }

}
}
