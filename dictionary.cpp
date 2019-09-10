#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

int disc[110], low[110], vis[110];
int onstack[110];

vector<vector<string> > adjlist;
map<string, int> idxmap;
int currmax = 1000;
vector<string> st;
vector<int> finalans;
int dtime = 0;
void printsol(){
  printf("%d\n", currmax);
  sort(finalans.begin(), finals.end());
  printf("%s", finalans[0].c_str());
  for(int i = 1; i < finalans.size(); i++) printf(" %s", finalans[i].c_str());
  printf("\n");
}
int scc(string currplace){
  int currnode = idxmap[currplace];
  disc[currnode] = low[currnode] = dtime++;
  vis[currnode] = 1;
  onstack[currnode] = 1;
  st.push_back(currplace);
  for(string i : adjlist[currnode]){
    int currneigh = idxmap[i];
    if(!vis[currneigh]){
      scc(i);
      low[currnode] = min(low[currnode], low[currneigh]);
    }
    else if (onstack[currneigh]){
      low[currnode] = min(low[currnode], disc[currneigh]);
    }
  }

  if(disc[currnode] == low[currnode]){
      int size = 0;
      vector<string> temp;
      while(st[st.size() - 1] != currnode){
        size++;
        temp.push_back(st[st.size() - 1]);
        onstack[st[st.size() - 1]] = 0;
        st.erase(st.end() - 1);
      }
      if(size < currmax){currmax = size; finalans = temp;}
  }
}


int main(){
  int n;
  while(scanf("%d\n", &n) && n){
    idxmap.clear();
    currmax = 1000;
    finalans.clear();
    st.clear();
    adjlist.assign(n+5, vector<string>());
    string line;
    for(int i = 0; i < n;i++){
      getline(cin, line);
      sstringstream st(line);
      string currplace, neighbors;
      st >> currplace;
      idxmap[currplace] = i;
      while(st >> neighbors){
        adjlist[i].push_back(neighbors);
      }
    }

    for(int i = 0; i < n+5;i++){
      disc[i] = low[i] = vis[i] = onstack[i] = 0;
    }

    auto it = idxmap.begin();
    for(;it != idxmap.end();it++){
        string currplace = (*it).first;
        if(!vis[idxmap[currplace]]){
            dtime = 0;
            scc(currplace);
        }
    }

    printsol();
  }
}
