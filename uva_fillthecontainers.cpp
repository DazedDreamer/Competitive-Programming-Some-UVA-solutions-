#include <cstdio>
#include <vector>


using namespace std;
int vessels[1001];

int check(int number_of_containers, int max_capacity, int number_of_vessels) {
    int currvol = 0, current_number_of_containers = 1;

    for (int i = 0; i < number_of_vessels; i++) {
        if (vessels[i] > max_capacity) return false;

        if (currvol + vessels[i] > max_capacity) {
            current_number_of_containers++;
            currvol = 0;
        }

        if (current_number_of_containers > number_of_containers) return false;

        currvol += vessels[i];
    }

    return true;
}

int main() {

    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int lo = 1, hi = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &vessels[i]);
            hi += vessels[i];
        }

        int ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(m, mid, n)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
