#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool primes[100001];

void sieve(){
    primes[0] = primes[1] = false;
    for(int i = 2; i <= 1000001;i++) {
        if (primes[i]) {
            for (int j = i * 2; j <= 1000001; j += i) {
                primes[j] = false;
            }
        }
    }
}


int main() {
    int n;
    memset(primes, true, sizeof(primes));
    sieve();
    
    while(scanf("%d", &n) && n){
        int k = 0;
        for(int i = 2; i <= n;i++){
            if(primes[i] && primes[n - i]){
                cout << n << " = " << i << " + " << n-i <<endl;
                k=1;
                break;
            }
        }
        
        if(!k)cout <<"Goldbach's conjecture is wrong."<<endl;
    }
}
