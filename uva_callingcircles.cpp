#include <vector>
#include <string.h>
#include <stack>
#include <map>
#include <iostream>
#define MAXN 100001
using namespace std;
int dtime = 0;
map<string, int> disc;
map<string, int> low;
map<string, int> stackmember;

void tarjan(map<string, vector<string>>& adjlist, const string &source, stack<string>& st){
    disc[source] = low[source] = ++dtime;
    stackmember[source] = 1;
    st.push(source);
    for(string j: adjlist[source]){
        if(!disc[j]){
            tarjan(adjlist, j, st);
            
            low[source] = min(low[source], low[j]);
        } else if(stackmember[j]){
            low[source] = min(low[source], disc[j]);
        }
    }
    
    if(disc[source] == low[source]){
        while(st.top() != source){
            stackmember[st.top()] = 0;
            cout<<st.top()<<", ";
            st.pop();
        }
        
        stackmember[st.top()] = 0;
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main(){
    int n ,m;
    int cas = 0;
    while(scanf("%d%d", &n, &m) && n+m){
        map<string, vector<string>> adjlist;
        disc.clear();
        low.clear();
        stackmember.clear();
        char first[26], second[26];
        while(m--){
            scanf("%s %s", first, second);
            adjlist[first].push_back(second);
        }
        
        stack<string> st;
        
        cout<<"Calling circles for data set "<<++cas<<":\n";
        for(auto it = adjlist.begin(); it != adjlist.end(); it++){
            if(!disc[(*it).first]){
                dtime = 0;tarjan(adjlist, (*it).first, st);
            }
        }
        
        cout<<endl;
    }
}
