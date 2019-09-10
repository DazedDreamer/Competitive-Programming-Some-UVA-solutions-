#include <cstdio>
#include <cstring>
#include <algorithm>


int pathsize[30][30], next[30][30], dist[30][30];


void compute(int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            for (int k = 0; k < s; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    next[j][k] = next[j][i];
                    pathsize[j][k] = pathsize[j][i] + pathsize[i][k];
                } else if (dist[j][k] == dist[j][i] + dist[i][k]) {
                    if (pathsize[j][k] > pathsize[j][i] + pathsize[i][k]) {
                        pathsize[j][k] = pathsize[j][i] + pathsize[i][k];
                        next[j][k] = next[j][i];
                    }
                }
            }
        }
    }
}


int main() {
    int s, p;
    scanf("%d%d\n", &s, &p);
    char first, second;
    int distance;
    //initialize
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            pathsize[i][j] = 1;
            next[i][j] = j;
            dist[i][j] = 1000000;
        }
    }
    while (p--) {
        scanf("%c %c %d\n", &first, &second, &distance);
        dist[first - 'A'][second - 'A'] = dist[second - 'A'][first - 'A'] = distance;

    }
    compute(s);
    int queries;
    scanf("%d\n", &queries);
    for (int i = 0; i < queries; i++) {
        if (i)getchar();
        scanf("%c %c", &first, &second);
        printf("%c", first);
        int curr = next[first - 'A'][second - 'A'];
        while (curr != second - 'A') {
            printf(" %c", curr + 'A');
            curr = next[curr][second - 'A'];
        }
        printf(" %c\n", curr + 'A');
    }

    return 0;
}
