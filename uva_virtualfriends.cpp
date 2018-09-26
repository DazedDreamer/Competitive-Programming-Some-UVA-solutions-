//
//  uva_virtualfriends.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

string find_parent(map<string, pair<string, int>> &network, string person){
    if(network[person].first != person)
        network[person].first = find_parent(network, network[person].first);
    
    return network[person].first;
}


void dounion(map<string, pair<string, int>> &network, string friend1, string friend2){
    string parent1 = find_parent(network, friend1);
    string parent2 = find_parent(network, friend2);
    
    if(parent1 == parent2) return;
    
    if(network[parent1].second > network[parent2].second){
        network[parent2].first = parent1;
        network[parent1].second += network[parent2].second;
    } else  {
        network[parent1].first = parent2;
        network[parent2].second += network[parent1].second;
    }
}


int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        map<string, pair<string, int>> network;
        int friendships;
        scanf("%d\n", &friendships);
        char line[101];
        char friend1[20], friend2[20];
        while(friendships--){
            gets(line);
            sscanf(line,"%s %s", friend1, friend2);
            if(strcmp(friend1,friend2) == 0) continue;
            if(network.count(friend1) == 0)
                network[friend1] = make_pair(friend1, 1);
            if(network.count(friend2) == 0)
                network[friend2] = make_pair(friend2, 1);
            dounion(network, friend1, friend2);
            cout<< network[find_parent(network, friend1)].second<<endl;
        }
    }
}

