#include <vector>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int getsquarelength(int ypos, int xpos, int n, int m, int l, int u, vector<vector<int>> (&grid), int currmax) {
    int length = currmax;
    int isdone = 0;
    int stepsize = 0;
    while (xpos+currmax+stepsize < m && ypos+currmax+stepsize < n && !isdone) {
        if (grid[ypos+currmax+stepsize][xpos+currmax+stepsize] >= l && grid[ypos+currmax+stepsize][xpos+currmax+stepsize] <= u) {
            length++;
            stepsize++;
        } else isdone++;
    }

    return length;
}

int main() {

    int n, m;
    vector<vector<int>> grid;
    while (scanf("%d%d", &n, &m) && n + m) {
        grid = vector<vector<int>>(500, vector<int>());
        int element;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &element);
                grid[i].push_back(element);
            }
        }

        int queries, l, u;

        scanf("%d", &queries);
        while (queries--) {
            scanf("%d%d", &l, &u);

            //solution
            int currmax = 0;

            for (int y = 0; y < n; y++) {
                vector<int>::iterator temp = lower_bound(grid[y].begin(), grid[y].end(), l);
                if(temp != grid[y].end()) { // if something greater than or equal to l is found
                    int index = distance(grid[y].begin(), temp);
                    int g = getsquarelength(y, index, n, m, l, u, grid, currmax);
                    if (g > currmax) currmax = g;
                }
            }

            printf("%d\n", currmax);

        }

        printf("-\n");
    }

    return 0;
}
