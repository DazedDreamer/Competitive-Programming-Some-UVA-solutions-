#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int heights[100001];

int simulate(int k, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (heights[0] > k){
                return 0;
            }

            if(heights[0] == k) k--;
        }
        else {
            if (heights[i] - heights[i - 1] == k) {
                k--;
            } else if (heights[i] - heights[i - 1] > k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int t, n, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        map<int, int> frequency;
        int hi = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &heights[i]);
            if (i == 0){ if(heights[i] > hi) hi = heights[i];}
            else {
            if (heights[i] - heights[i - 1] > hi) hi = heights[i] - heights[i - 1];}
        }
        if (n == 1) printf("Case %d: %d\n", ++cas, heights[0]);
        else {
            hi++;
            int lo = 1, mid, ans;
            while (lo <= hi) {
                mid = (lo + hi) / 2;

                if (simulate(mid, n)) {
                    ans = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }

            printf("Case %d: %d\n", ++cas, ans);
        }
    }

    return 0;
}
