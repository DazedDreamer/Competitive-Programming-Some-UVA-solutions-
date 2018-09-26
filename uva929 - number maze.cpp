#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <numeric>
#include <climits>

using namespace std;

int mazes, rows, cols, cost;
int grid[999 + 5][999 + 5];
bool splset[999 + 5][999 + 5];
int dist[999 + 5][999 + 5];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool is_initialized;

void initialize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dist[i][j] = INT_MAX;
            splset[i][j] = false;
            
        }
    }
    dist[0][0] = grid[0][0];
}


int main() {
    scanf("%d", &mazes);
    while (mazes--) {
        scanf("%d%d", &rows, &cols);
        int i = 0;
        while (i < rows) {
            int j = 0;
            while (j < cols) {
                scanf("%d", &cost);
                grid[i][j] = cost;
                j++;
            }
            i++;
        }
        initialize();
        
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min;
        min.push(make_pair(grid[0][0], make_pair(0, 0)));
        
        while (!(min.empty())) {
            pair<int, pair<int, int>> p = min.top();
            min.pop();
            int currx = p.second.first;
            int curry = p.second.second;
            splset[currx][curry] = true;
            for (int n = 0; n < 4; n++) {
                int newcurrx = currx + dx[n];
                int newcurry = curry + dy[n];
                if (newcurrx >= 0 && newcurrx < rows && newcurry >= 0 && newcurry < cols &&
                    !splset[newcurrx][newcurry]) {
                    if (dist[currx][curry] + grid[newcurrx][newcurry] < dist[newcurrx][newcurry]) {
                        dist[newcurrx][newcurry] = dist[currx][curry] + grid[newcurrx][newcurry];
                        min.push(make_pair(dist[newcurrx][newcurry], make_pair(newcurrx, newcurry)));
                    }
                }
            }
        }
        
        if (mazes != 0) printf("%d\n", dist[rows - 1][cols - 1]);
        else printf("%d", dist[rows - 1][cols - 1]);
    }
    
    return 0;
}
