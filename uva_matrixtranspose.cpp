//
//  uva_matrixtranspose.cpp
//  Solution
//
//  Created by Snehil Chopra on 9/26/18.
//  Copyright © 2018 Snehil Chopra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    vector<vector<pair<int, int>>> matrix;
    vector<int> indices;
    vector<int> elements;
    int row, col, trow, tcol;
    while (scanf("%d%d", &row, &col) != EOF) {
        matrix.clear();
        trow = col, tcol = row;
        int r, indice, element;
        for (int e = 1; e < row + 1; e++) {
            indices.clear();
            elements.clear();
            scanf("%d", &r);
            for (int i = 0; i < r; i++) {
                scanf("%d", &indice);
                indices.push_back(indice);
            }
            
            for (int i = 0; i < r; i++) {
                scanf("%d", &element);
                elements.push_back(element);
            }
            
            for (int i = 0; i < indices.size(); i++) {
                while (matrix.size() < indices[i]) {
                    vector<pair<int, int>> temp;
                    temp.push_back(make_pair(0, 0));
                    matrix.push_back(temp);
                }
                
                
                matrix[indices[i] - 1].push_back(make_pair(e, elements[i]));
            }
        }
        
        //print the solution
        printf("%d %d\n", trow, tcol);
        for (int i = 0; i < matrix.size(); i++) {
            if(matrix[i].size() >1) {
                printf("%d ", matrix[i].size() - 1);
                for (int m = 1; m < matrix[i].size(); m++) {
                    if (m == matrix[i].size() - 1) printf("%d\n", matrix[i][m].first);
                    else printf("%d ", matrix[i][m].first);
                }
                
                for (int m = 1; m < matrix[i].size(); m++) {
                    if (m == matrix[i].size() - 1) printf("%d\n", matrix[i][m].second);
                    else printf("%d ", matrix[i][m].second);
                }
            }  else {
                cout<<0<<endl<<endl;
            }
        }
        
        //cout<<endl;
    }
    
    return 0;
}
