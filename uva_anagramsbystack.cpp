//
//  uva_anagramsbystack.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
void print(int l, int o, vector<char> stk, string source, string target, int wordindex, stack<char> word){
    if(l == target.size() && o == target.size()){
        for(int i = 0; i < stk.size(); i++){
            if(i == stk.size() - 1)cout<<stk[i];
            else cout<<stk[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(l < source.size()){
        stk.push_back('i');
        word.push(source[l]);
        print(l+1, o, stk, source, target, wordindex,word);
        stk.erase(stk.end() - 1);
        word.pop();
    }
    
    if(o < l){
        if(word.top() == target[wordindex]){
            stk.push_back('o');
            word.pop();
            print(l, o+1, stk, source, target, wordindex+1, word);
        }
    }
}
int main(){
    char source[100000], target[100000];
    while((scanf("%s\n%s", source, target) == 2)){
        vector<char> st;
        stack<char> word;
        if(strlen(source) != strlen(target)){
            cout<<"[\n]"<<endl;
        } else {
            cout<< "[\n";
            print(0,0, st, source, target, 0, word);
            cout<< "]\n";
        }
    }
    return 0;
}
