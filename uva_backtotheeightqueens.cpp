#include <iostream>
#include <string.h>
using namespace std;
int pos[9], sol_pos[9], ans;
bool issafe(int row, int queen_no) {
    for (int i = 0; i < queen_no; i++) {
        if (sol_pos[i] == row || abs(i - queen_no) == abs(sol_pos[i] - row)) return false;
    }
    return true;
}
void solve(int numofmoves, int queen_no) {
    if (queen_no >= 8) {
        if (numofmoves < ans) ans = numofmoves;
        return;
    }
    for (int row = 0; row <= 7; row++) {
        if (issafe(row, queen_no)) {
            sol_pos[queen_no] = row;
            if (row == pos[queen_no]) solve(numofmoves, queen_no + 1);
            else solve(numofmoves + 1, queen_no + 1);
        }
    }
}
int main() {
    int cas = 0;
    while (scanf("%d%d%d%d%d%d%d%d", &pos[0], &pos[1], &pos[2], &pos[3], &pos[4], &pos[5], &pos[6], &pos[7]) == 8) {
        for(int& i:pos)i--;
        ans = 9;
        solve(0, 0);
        cout << "Case " << ++cas << ": " << ans << endl;
    }
    return 0;
}

