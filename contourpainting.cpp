#include <cstdio>
#include <cstring>

int ext = 0;
int rows, cols;
// replace X with e
void fillexterior(int currx, int curry,  char (&grid)[40][100]){
    if(currx < 0 || curry < 0 || curry >= rows)return;
    if(grid[curry][currx] == '*') ext = 1;
    if(grid[curry][currx] != ' ') return;
    grid[curry][currx] = '.';
    fillexterior(currx+1, curry, grid);
    fillexterior(currx-1, curry, grid);
    fillexterior(currx, curry+1, grid);
    fillexterior(currx, curry-1, grid);

}

void paintoutside(int currx, int curry,  char (&grid)[40][100]){
    if(grid[curry][currx] == '.'){ grid[curry][currx] = '#'; return;}
    if(grid[curry][currx] != 'X') return;
    grid[curry][currx] = 'e';
    paintoutside(currx+1, curry, grid);
    paintoutside(currx-1, curry, grid);
    paintoutside(currx, curry+1, grid);
    paintoutside(currx, curry-1, grid);

}

void paintinside(int currx, int curry, char (&grid)[40][100]){
    if(grid[curry][currx] == ' '){grid[curry][currx] = '#'; return;}
    if(grid[curry][currx] != 'X') return;
    grid[curry][currx] = 'e';
    paintinside(currx+1, curry, grid);
    paintinside(currx-1, curry, grid);
    paintinside(currx, curry+1, grid);
    paintinside(currx, curry-1, grid);
}

int main(){
    int t;
    scanf("%d\n", &t);
    char grid[40][100];

    while(t--){
        memset(grid, 0, sizeof grid);
        int idx = 1;
        while(fgets(grid[idx], 100, stdin) && grid[idx][0] != '_'){
            idx++;
        }
        //cols = strlen(grid[0])-1;
        rows = idx;
        cols += 2;
        fillexterior(0,0, grid);
        int found = 0;
        for(int i = 0; i < rows && !found;i++){
            for(int j = 0; grid[i][j] != '\n';j++){
                if(grid[i][j] == 'X'){
                    if(ext) paintoutside(i,j,grid);
                    else paintinside(i,j,grid);
                    found = 1;
                    break;
                }
            }
        }
    }
}
