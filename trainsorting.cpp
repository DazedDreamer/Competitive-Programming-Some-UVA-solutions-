
#include <vector>
#include <iostream>
using namespace std;

int lds[2500], lis[2500], cars[2500];

int main() {

    int x, n;

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int num;

        scanf("%d", &num);

        for(int i = 0; i < num; i++){
            scanf("%d", &cars[i]);
            lis[i] = lds[i] = 1;
        }

        int finalans = -1;
        for(int i = num-1; i>=0; i--){
            for(int j = i + 1; j  < num;j++){
                if(cars[i] < cars[j]) lis[i] = max(lis[i], lis[j] + 1);
                if(cars[i] > cars[j]) lds[i] = max(lds[i], lds[j] + 1);
            }

            finalans = max(finalans, lds[i] + lis[i] - 1);
        }

        printf("%d\n", finalans);
    }
}
