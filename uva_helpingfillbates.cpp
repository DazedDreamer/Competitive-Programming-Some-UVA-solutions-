#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> indices(256, vector<int>());

int main() {

    char S[1000001];
    scanf("%s", S);


    for(int i = 0; S[i]; i++){
        indices[S[i]].push_back(i);
    }


    int queries;
    scanf("%d", &queries);

    char currquery[102];
    while(queries--){

        scanf("%s", currquery);
        int currlastindex = -1;
        int firstindex = -1;
        int notfound = 0;
        for(int i = 0; currquery[i] && !notfound; i++){
            auto temp = lower_bound(indices[currquery[i]].begin(), indices[currquery[i]].end(), currlastindex+1);
            if(temp == indices[currquery[i]].end()){
                notfound = 1;
            } else {
                if(firstindex < 0) firstindex = *temp;
                currlastindex = *temp;
            }
        }

        if(notfound) printf("Not matched\n");
        else printf("Matched %d %d\n", firstindex, currlastindex);

    }
}
