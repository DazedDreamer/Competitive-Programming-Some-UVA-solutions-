#include <iostream>
#include <string.h>

using namespace std;
int maxsurplus;
int months[13];

int getpast5sum(int monthindex) {
    int sum = 0;
    for (int i = monthindex; i > monthindex - 5; i--) {
        sum += months[i];
    }
    return sum;
}

void solve(int& currsum, int &s, int &d, int monthindex) {
    if (monthindex > 5 && getpast5sum(monthindex - 1) > 0) return;
    if (monthindex == 13) {
        if (currsum > maxsurplus) maxsurplus = currsum;
        return;
    }
    currsum += s;
    months[monthindex++] = s;
    solve(currsum, s, d, monthindex);
    currsum -= s;
    monthindex--;
    months[monthindex++] = -d;
    currsum -= d;
    solve(currsum, s, d, monthindex);
    currsum += d;
    
    
}

int main() {
    int s, d;
    while (scanf("%d%d", &s, &d) != EOF) {
        memset(months, 0, 13);
        int sum = 0; // helper
        maxsurplus = 0;
        solve(sum, s, d, 1);
        if (maxsurplus > 0) cout << maxsurplus << endl;
        else cout << "Deficit" << endl;
    }
    return 0;
}


