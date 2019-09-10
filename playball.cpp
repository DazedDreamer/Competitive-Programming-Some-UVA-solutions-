#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>

using namespace std;
struct player {
    int x, y, v;
};

player players[21];

int main() {
    int a, b, c, d, e, f, g;
    int numplayers;
    int numballs;
    scanf("PLAYERS=%d\n", &numplayers);
    for (int i = 0; i < numplayers; i++) {
        scanf("%d%d%d\n", &players[i].x, &players[i].y, &players[i].v);
    }

    scanf("BALLS=%d\n", &numballs);
    for (int i = 0; i < numballs; i++) {
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
        // now start at time t, where t >= 1, and then find out when z hits 0
        // discardable cases : when x < 0 or y < 0
        int hittime = 0;
        for (int time = 1; !hittime; time++) {
            int currz = a * time * time + b * time + c;
            if (currz <= 0) hittime = time;
        }

        // check if foul
        int x = d * hittime + e;
        int y = f * hittime + g;
        if (x < 0 || y < 0) {
            printf("Ball %d was foul at (%d,%d)\n", i + 1, x, y);
            continue;
        }

        // now, for each player, check how much distance they can cover
        // in 'hittime - 1'
        // then, if the euclidean distance between landing point a player's point is
        // <= distance that can be covered by the players in hittime-1
        int flag = 1;
        for (int j = 0; j < numplayers && flag; j++) {
            double distancecoverable = (double) players[j].v * (hittime);
            int dx = abs(x - players[j].x);
            int dy = abs(y - players[j].y);
            double dist = sqrt(dx * dx + dy * dy);
            if (distancecoverable >= dist) {
                printf("Ball %d was caught at (%d,%d)\n", i + 1, x, y);
                flag = 0;
            }
        }
        if(flag){
            printf("Ball %d was safe at (%d,%d)\n", i+1, x,y);
        }
    }

}
