//
//  uva_wordtransformation.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>


#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

bool isadjacent(const string &word1, const string &word2) {
    int count = 0;
    
    if (word1.size() != word2.size()) {
        return false;
    }
    
    for (int i = 0; i < word1.size(); i++) {
        if (word2[i] != word1[i]) {
            count++;
        }
        
    }
    
    return (count == 1);
}


int main() {
    int n;
    scanf("%d", &n);
    
    
    while (n--) {
        vector<string> dictionary;
        char w[201][20];
        char s[101];
        int i = 0;
        while(gets(s)){
            if(s[0] == '\0')  continue;
            sscanf(s, "%s", w[i]);
            if (w[i][0] == '*') {
                break;
            }
            dictionary.push_back(w[i]);
            i++;
        }
        
        while (gets(s)) {
            vector<string> temp_dictionary = dictionary;
            if(s[0] == '\0') break;
            
            char st[20], sy[20];
            sscanf(s, "%s%s", st, sy);
            string starting_word = st, ending_word = sy;
            
            cout << starting_word << " " << ending_word << " ";
            if (starting_word == ending_word) {
                cout << 0 << endl;
                continue;
            }
            
            queue<string> q;
            q.push(st);
            queue<int> depthqueue;
            depthqueue.push(0);
            bool has_ended = false;
            while (!q.empty() && !has_ended) {
                string currword = q.front();
                int currdepth = depthqueue.front();
                depthqueue.pop();
                vector<string>::iterator it;
                q.pop();
                
                // explore all the words in the dictionary
                for (it = temp_dictionary.begin(); it != temp_dictionary.end(); ) {
                    if(starting_word == * it){
                        temp_dictionary.erase(it);
                    }
                    
                    if (isadjacent(currword, *it)) {
                        if (*it == ending_word) {
                            cout << currdepth + 1<< endl;
                            has_ended = true;
                            break;
                        }
                        
                        q.push(*it);
                        depthqueue.push(currdepth + 1);
                        temp_dictionary.erase(it);
                    } else {
                        ++it;
                    }
                }
                
            }
        }
        if(n != 0) cout<<endl;
    }
    
    return 0;
}

