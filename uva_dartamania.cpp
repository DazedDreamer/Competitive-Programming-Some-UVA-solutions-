#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool visited[61][61][61];
vector<int> scores;
bool checked[61];
int permutations, combinations;
void initialize() {
    for (int i = 0; i <= 20; i++) {
        for (int j = 1; j <= 3; j++) {
            if (!checked[i * j]) {
                scores.push_back(i * j);
                checked[i * j] = true;
            }
        }
    }
    scores.push_back(50);
}
int main() {
    int target;
    initialize();
    while (scanf("%d", &target) && target > 0) {
        permutations = combinations = 0;
        memset(visited, false, sizeof(visited));
        memset(checked, false, sizeof(checked));
        for (int i = 0; i < scores.size(); i++) {
            for (int j = 0; j < scores.size(); j++) {
                for (int k = 0; k < scores.size(); k++) {
                    if (!visited[scores[i]][scores[j]][scores[k]])
                        if (scores[i] + scores[j] + scores[k] == target) {
                            permutations++;
                            if (!(visited[scores[i]][scores[j]][scores[k]] ||
                                  visited[scores[i]][scores[k]][scores[j]] ||
                                  visited[scores[j]][scores[i]][scores[k]] ||
                                  visited[scores[j]][scores[k]][scores[i]] ||
                                  visited[scores[k]][scores[i]][scores[j]] ||
                                  visited[scores[k]][scores[j]][scores[i]]))
                                combinations++;
                        }
                    visited[scores[i]][scores[j]][scores[k]] = true;
                }
            }
        }
        if (combinations) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << target << " IS " << combinations << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << target << " IS " << permutations << "." << endl;
        } else {
            cout << "THE SCORE OF " << target << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        for (int i = 0; i < 70; i++)cout << "*";
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
}
