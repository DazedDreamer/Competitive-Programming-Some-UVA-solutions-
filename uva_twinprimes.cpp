#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool primes[20000000];

void sieve(vector<int>& prime) {
    primes[0] = primes[1] = false;
    
    for (int i = 2; i <= 20000000; i++) {
        if (primes[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 20000000; j+=i) {
                primes[j] = false;
            }
        }
    }
}


int main() {
    
    int n;
    vector<int> prime;
    vector<pair<int, int>> pairs;
    prime.clear();
    memset(primes, true, sizeof(primes));
    sieve(prime);
    
    for (int j = 0; j < prime.size() - 1; j++) {
        if (prime[j] + 2 == prime[j+1]) {
            pairs.push_back(make_pair(prime[j], prime[j+1]));
        }
    }
    
    while (scanf("%d", &n) == 1) {
        printf("(%d, %d)\n", pairs[n-1].first, pairs[n-1].second);
    }
    
    
    return 0;
}
