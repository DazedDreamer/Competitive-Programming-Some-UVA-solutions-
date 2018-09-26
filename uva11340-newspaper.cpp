#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main(){
    int testcase;
    
    scanf("%d", &testcase);
    while (testcase--){
        int num;
        map<char, int> cost;
        char c;
        int k;
        scanf("%d", &num);
        while(num--) {
            scanf("%c %d", &c, &k);
            cost[c] = k;
        }
        
        int numoflines;
        scanf("%d", &numoflines);
        char  lines[numoflines][10000];
        
        for(int line = 0; line < numoflines; line++) {
            scanf("%s\n", lines[line]);
            
        }
    }
}
