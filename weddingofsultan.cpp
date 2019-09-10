#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

vector<int> counter;
stack<char> st;
int main(){
  int t;
  int cas = 0;

  scanf("%d\n", &t);
  char line[1000];
  while(t--){
    fgets(line, 1000, stdin);
    counter.assign(30,0);

    for(int  i = 0; line[i] != '\n'; i++){
      if(i == 0){
        st.push(line[i]);
        continue;
      }

      int currchar = line[i];

      if(currchar == st.top()) st.pop();

      else {
        counter[currchar - 'A']++;
        counter[st.top() - 'A']++;
        st.push(currchar);
      }

    }

    printf("Case %d\n", ++cas);
    for(int i = 0; i < 26;i++){
      if(counter[i]) printf("%c = %d\n", 'A' + i, counter[i]);
    }
  }
}
