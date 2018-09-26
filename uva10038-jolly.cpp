#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

int main(){
    string l;
    int n;
    int number;
    while(getline(cin, l)){
        if(l.empty()){
            break;
        }
        
        istringstream inp(l);
        inp>>n;
        if(n==1){
            inp>>number;
            printf("Jolly\n");
            continue;
        }
        int j = 0;
        vector<int> numbers;
        for(int i =0; i < n; i++){
            inp>>number;
            numbers.push_back(number);
        }
        set<int> differences;
        for(int j = 0; j < n - 1;j++){
            int diff = abs(numbers[j] - numbers[j+1]);
            if(!(diff <= 0 || diff > n - 1)) differences.insert(diff);
        }
        
        if(differences.size() != n - 1)printf("Not Jolly\n");
        else printf("Jolly\n");
    }
    return 0;
}
