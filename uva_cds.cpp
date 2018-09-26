#include <iostream>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;

vector<int> potential;
vector<int> mins;
int ans;
vector<int> cds;
void solve(int& total, int& limit, vector<int>& possiblesol, int pos){
    bool flag = false;
    for(int i = pos; i < mins.size();i++){
        if(mins[i]+total <= limit){
            possiblesol.push_back(mins[i]);
            total+=mins[i];
            solve(total, limit, possiblesol, i+1);
            total -= mins[i];
            possiblesol.pop_back();
            flag = true;
        }
    }
    
    if(!flag) {
        if(total > ans){
            ans = total;
            cds.clear();
            for(int i: possiblesol) cds.push_back(i);
        }
    }
    
}

int main(){
    int n,m;
    while(scanf("%d%d", &n, &m) == 2){
        mins.clear();
        
        
        int min;
        ans = INT_MIN;
        potential.clear();
        while(m--){
            scanf("%d", &min);
            mins.push_back(min);
        }
        int total = 0;
        vector<int> possiblesol;
        int pos = 0;
        solve(total, n, possiblesol, pos);
        int sum = 0;
        for(int& i: cds){
            cout<<i<<" ";
            sum+=i;
        }
        
        cout<<"sum:"<<sum<<endl;
    }
}
  
