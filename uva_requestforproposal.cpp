#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(pair<int, pair<string, pair<double, int>>> &p1, pair<int, pair<string, pair<double, int>>> &p2) {
    if (p1.first > p2.first) return true;

    else if (p1.first == p2.first) {
        if (p1.second.second.first < p2.second.second.first) return true;

        if (p1.second.second.first == p2.second.second.first) {
            if (p1.second.second.second < p2.second.second.second) return true;

        }
    }

    return false;
}

int main() {
    int n, p;
    int cas = 0;
    while (scanf("%d%d", &n, &p) && n + p) {
        char currstring[90];
        vector<pair<int, pair<string, pair<double, int>>>> proposals;
        double price;
        int reqmet;
        getchar();
        if(cas) cout<<endl;
        while (n--) {
            gets(currstring);
        }


        for (int i = 0; i < p; i++) {
            gets(currstring);
            scanf("%lf %d\n", &price, &reqmet);
            string curr = currstring;
            for (int j = reqmet; j; j--) {
                gets(currstring);
            }
            proposals.push_back(make_pair(reqmet, make_pair(curr, make_pair(price, i))));
        }

        sort(proposals.begin(), proposals.end(), cmp);

        cout << "RFP #" << ++cas << endl << proposals[0].second.first << endl;

    }

    return 0;
}
