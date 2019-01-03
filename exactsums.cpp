#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int prices[100001];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int price;
        for (int i = 0; i < n; i++) {
            scanf("%d", &prices[i]);
        }


        int target;
        scanf("%d", &target);

        // collapsing wall algorithm

        sort(prices, prices + n);

        int i = 0, j = n - 1;
        int price1 = 0, price2 = 0;

        while (i < j) {
            if (prices[i] + prices[j] < target) {
                i++;
            } else if (prices[i] + prices[j] == target) {

                price1 = prices[i++];
                price2 = prices[j--];


            } else {
                j--;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", price1, price2);
    }
}
