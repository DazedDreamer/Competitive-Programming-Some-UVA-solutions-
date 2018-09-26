#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;


bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int chosen[17];

void solve(vector<int> &p, int &n, int curr_index) {
    if (p.size() == n && is_prime(p[n - 1] + 1)) {
        for (int i = 0; i < p.size();i++){
            if(i == p.size()-1)cout<<p[i];
            else cout<<p[i]<<" ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 2; i <= n; i++) {
        if (!chosen[i] && is_prime(p[curr_index] + i)) {
            chosen[i] = 1;
            p.push_back(i);
            solve(p, n, curr_index + 1);
            chosen[i] = 0;
            p.pop_back();
        }
    }
}

int main() {
    int n, cas = 0;
    while (scanf("%d", &n) == 1) {
        memset(chosen, 0, 17);
        vector<int> p;
        if(cas)cout<<endl;
        p.push_back(1);
        cout << "Case " << ++cas << ":" << endl;
        solve(p, n, 0);
    }
}

