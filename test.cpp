#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int disc[100], low[100], dtime = 0, onstack[100]; // set disc to -1, low to 0
vector<vector<int> > adjlist;
vector<int> st;
vector<vector<int> > sccs;
void scc(int currnode){
    disc[currnode] = low[currnode] = dtime++;
    st.push_back(currnode);
    onstack[currnode] = 1;
    for(int i = 0; i< adjlist[currnode].size();i++){
        int currneigh = adjlist[currnode][i];

        if(disc[currneigh] == -1){
            scc(currneigh);
            low[currnode] = min(low[currnode], low[currneigh]);
        }

        else if (onstack[currneigh]) low[currnode] = min(low[currnode], disc[currneigh]);
    }

    if(disc[currnode] == low[currnode]){
        vector<int> temp;
        while(1){
            temp.push_back(st.back()); st.pop_back();
            onstack[temp[temp.size() - 1]] = 0;
            if(temp[temp.size() - 1] == currnode) break;
        }
        sort(temp.begin(), temp.end());
        sccs.push_back(temp);
    }
}

int main(){
    int n, cas = 0;
    while(scanf("%d\n", &n) && n){
        if(cas++) printf("\n");
        char line[400];
        adjlist.assign(30, vector<int>());
        memset(line, 0, 350);
        set<int> there;
        sccs.clear();
        for(int i = 0; i < n;i++){

            fgets(line, 350, stdin);
            int size = strlen(line);
            int currplace = line[size-2]- 'A';
            there.insert(currplace);
            for(int j =0; j < size-2;j++){
                if(line[j] != ' '){

                    disc[line[j] - 'A'] = -1; low[line[j] - 'A'] = onstack[line[j] - 'A'] = 0;
                    there.insert(line[j] - 'A');
                    adjlist[currplace].push_back(line[j] - 'A');
                }
            }
        }

        for(int i: there){
            if(disc[i] == -1){scc(i);}
        }

        sort(sccs.begin(), sccs.end());

        for(auto i: sccs){
            for(int j = 0; j < i.size();j++){
                if(j) printf(" ");
                printf("%c", 'A' + i[j]);
            }
            printf("\n");
        }
    }
}
