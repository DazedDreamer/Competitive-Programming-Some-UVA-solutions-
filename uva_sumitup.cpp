/**
 * @file
 * Contains an implementation of the countOnes function.
 */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
map<int, int> count_;
vector<string> sols;
bool has_sol;
void solve(int currsum, int &target, vector<int> &numbers, vector<int> &possol, int currpos) {
    if (currsum == target) {
        has_sol = true;
        string ans = "";
        for (int i = 0; i < possol.size(); i++) {
            if (i == possol.size() - 1) ans += to_string(possol[i]);
            else ans+= to_string(possol[i]) + "+";
        }
        if (find(sols.begin(), sols.end(), ans) == sols.end()) sols.push_back(ans);
        return;
    } else if (currsum > target) return;
    else {
        for(int i = currpos; i < numbers.size(); i++){
            if(count_[numbers[i]] && numbers[i] + currsum <= target){
                possol.push_back(numbers[i]);
                count_[numbers[i]]--;
                solve(currsum+numbers[i], target, numbers, possol, i+1);
                count_[numbers[i]]++;
                possol.erase(possol.end()-1);
            }
        }
    }
}

int main() {
    int target, n;
    vector<int> numbers;
    while (scanf("%d%d", &target, &n) && n + target) {
        count_.clear();
        has_sol = false;
        sols.clear();
        int num;
        numbers.clear();
        while (n--) {
            scanf("%d", &num);
            count_[num]++;
            numbers.push_back(num);
        }
        vector<int> sol;
        solve(0, target, numbers, sol, 0);
        //sort(numbers.begin(), numbers.end());
        
        cout<<"Sums of "<<target<<":"<<endl;
        
        if(!has_sol)cout<<"NONE"<<endl;
        else for(auto i: sols)cout<<i<<endl;
    }
}
