#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

vector<string> grid1, grid2;
int k;
int notpossible = 0;

void solve(int &k, vector<char> currstring, int &is_done, vector<vector<char>> (&lines), int currlength) {
    if (currlength == 5) {
        k--;
        if (k == 0) {
            for (auto j: currstring)printf("%c", j);
            printf("\n");
            is_done = 1;
        }
        return;
    }
    for (int i = 0; i < lines[currlength].size() && !is_done ; i++) {
        if(i > 0 && lines[currlength][i] == lines[currlength][i-1]) continue; // avoid similar passwords
        currstring.push_back(lines[currlength][i]);
        solve(k, currstring, is_done, lines, currlength + 1);
        currstring.erase(currstring.end() - 1);
    }

}

int main() {


    int t;
    scanf("%d", &t);
    while (t--) {
        notpossible = 0;
        grid1.clear();
        grid2.clear();
        vector<vector<char>> lines(5, vector<char>());
        scanf("%d", &k);

        char line[20];
        int size = 12 / 2;
        while (size--) {
            scanf("%s", line);
            string temp = (string) line;
            grid1.push_back(temp);
        }

        size = 6;
        while (size--) {
            scanf("%s", line);
            string temp = line;
            grid2.push_back(temp);
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) { // traverse column wise both the arrays and find the intersection
                char temp = grid1[j][i];
                for (int h = 0; h < 6; h++) {
                    if (temp == grid2[h][i]) { // check if the certain character in a column exists in both the grids
                        lines[i].push_back(temp);
                        break;
                    }
                }
            }
        }

        // sort each row
        for (int i = 0; i < 5; i++) {
            sort(lines[i].begin(), lines[i].end());
        }

        // now recursively backtrack
        vector<char> currstring;
        int is_done = false;
        solve(k, currstring, is_done, lines, 0);

        if(!is_done)printf("NO\n");
    }

    return 0;
}
