// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// // dp[i][j] = maxmimum variety of coins from 0 to j for sum i
// using namespace std;
// long long dp[1000000000][1002], coin[1005];
// long long solve(long i, int j){
//     if(i == 0) return 0;
//     if(j == 0) return 1;
//     long long & ret = dp[i][j];
//
//     if(ret != -1) return ret;
//     ret = solve(i, j-1);
//     if(coin[j] <= i){
//         ret = 1+solve(i % coin[j], j-1);
//     }
//
//     return ret;
// }
//
//
// int main(){
//     int t;
//     scanf("%d", &t);
//     while(t--){
//         int num;
//         scanf("%d", &num);
//         for(int i = 0; i < num; i++){
//             scanf("%lld", coin+i);
//         }
//         if(num == 1){
//             printf("1\n"); continue;
//         }
//
//         for(int i = 0; i<coin[num-1]; i++)for(int j = 0; j < num-1; j++)
//             dp[i][j] = -1;
//
//
//         // run a loop, trying for all sums from coin[0] to coin[i-1]-1
//         long long currmax = -1; // add 1 to this for the final ans, because you will always want
//                                 // to include the largest coin
//         for(long long i = 1; i < coin[num-1]; i ++){
//             long long ret = solve(i, num-2);
//             if(ret > currmax) currmax = ret;
//         }
//
//         printf("%lld\n", currmax+1); //
//     }
// }

#include<cstdio>

int c[1005];

int main()
{
	int t, n, i, sum, count;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &c[i]);
		if (n <= 2) printf("%d\n", n);
		else
		{
			sum = c[0], count = 2;
			for (i = 1; i < n - 1; ++i)
				if (sum < c[i] && sum + c[i] < c[i + 1])
					sum += c[i], ++count;
			printf("%d\n", count);
		}
	}
	return 0;
}
