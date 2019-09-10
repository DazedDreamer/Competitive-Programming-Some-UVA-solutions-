#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


//vector<vector<string> > adjlist;
map<string, int> indegree;
map<string, vector<string> > adjlist;
int currmax = 0;
int noans = 0;
//void printsol(){
//    printf("%d\n", currmax);
//    sort(finalans.begin(), finalans.end());
//    printf("%s", finalans[0].c_str());
//    for(int i = 1; i < finalans.size(); i++) printf(" %s", finalans[i].c_str());
//    printf("\n");
//}


void printsol(){
    vector<string> finalans;
    auto it = indegree.begin();
    for(;it != indegree.end();it++){
        finalans.push_back(it->first);
    }
    printf("%d\n", finalans.size());
    printf("%s", finalans[0].c_str());
    for(int i = 1; i < finalans.size(); i++) printf(" %s", finalans[i].c_str());
    printf("\n");

}
void remove(){
    while(true){
        auto it = indegree.begin();

        int found = 0;
        for(;it != indegree.end(); it++){
            int currdegree = it->second;
            if(currdegree == 0){
                found = 1;
                // reduce the indegree of the neighbors
                for(auto i: adjlist[it->first]){
                    indegree[i]--;
                }
                indegree.erase(indegree.find(it->first));
            }
            if(found){
                break;
            }
        }
        if(!found){
            if(indegree.size() == 0) noans = 1;
            return;
        }
    }
}

int main(){
    int n;
    while(scanf("%d\n", &n) && n){
        indegree.clear();
        adjlist.clear();
        currmax = 0;
        string line;
        for(int i = 0; i < n;i++){
            getline(cin, line);
            stringstream st(line);
            string currplace, neighbors;
            st >> currplace;
            if(indegree.find(currplace) == indegree.end()) {
                indegree[currplace] = 0;
            }
            while(st >> neighbors){
                adjlist[currplace].push_back(neighbors);
                indegree[neighbors]++;
            }
        }
        // now take out the places which dont have an incoming edge
        remove();
        printsol();
    }
}
