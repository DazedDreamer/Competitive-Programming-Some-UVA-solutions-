
#include<algorithm>
#include <climits>
#include<cstdio>

using namespace std;

int T, N;

int main() {
    int A[500][500];

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N * 2; i++) {
            for(int j = 0; j < N * 2; j++) {
                if(i < N && j < N) {
                    scanf("%d", &A[i][j]);
                    A[i + N][j] = A[i][j + N] =
                    A[i + N][j + N] = A[i][j];
                }
                if(i > 0) A[i][j] += A[i - 1][j];
                if(j > 0) A[i][j] += A[i][j - 1];
                if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {

                for(int i1 = i; i1 < i + N; i1++) {
                    for(int j1 = j; j1 < j + N; j1++) {
                        int cur = A[i1][j1];
                        if(i > 0) cur -= A[i - 1][j1];
                        if(j > 0) cur -= A[i1][j - 1];
                        if(i > 0 && j > 0)
                            cur += A[i - 1][j - 1];
                        ans = max(ans, cur);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}
