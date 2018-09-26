//
//  uva_wakingupbrains.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>
#include<set>
#include <string.h>

using namespace std;

int main(void) {
    int sleptareas;
    bitset<26> areas;
    while (scanf("%d\n", &sleptareas) == 1) {
        int m, years = 0;
        scanf("%d\n", &m);
        areas.reset();
        bool letters[26];
        memset(letters, false, sizeof(letters));
        vector<char> neighbors[26];
        char awakeareas[30];
        scanf("%s\n", awakeareas);
        for (int i = 0; i < strlen(awakeareas); i++) {
            areas.set(awakeareas[i] - 'A');
        }
        
        while (m--) {
            scanf("%s\n", awakeareas);
            letters[awakeareas[0] - 'A'] = true;
            letters[awakeareas[1] - 'A'] = true;
            neighbors[awakeareas[0] - 'A'].push_back(awakeareas[1]);
            neighbors[awakeareas[1] - 'A'].push_back(awakeareas[0]);
        }
        
        bool is_possible = true;
        
        while (areas.count() < sleptareas) {
            vector<int> awake_areas;
            for (int i = 0; i < 26; i++) {
                int awake_neighbors = 0;
                int j = areas[i];
                if (letters[i] && !areas[i]) {
                    for (char c: neighbors[i]) {
                        if (areas[c - 'A']) awake_neighbors++;
                    }
                    if (awake_neighbors >= 3) awake_areas.push_back(i);
                }
            }
            
            if(awake_areas.empty()){
                is_possible = false;
                break;
            }
            
            for (int k:awake_areas){
                areas.set(k);
                
            }
            years++;
        }
        
        if (!is_possible) printf("THIS BRAIN NEVER WAKES UP\n");
        else printf("WAKE UP IN, %d, YEARS\n", years);
    }
}
