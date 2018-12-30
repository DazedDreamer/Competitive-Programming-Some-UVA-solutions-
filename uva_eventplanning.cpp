#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(){
    int n, b,h,w;


    while(scanf("%d%d%d%d", &n, &b, &h, &w) == 4){
        int priceperperson;
        int min_cost = INT_MAX;

        while(h--) {
            scanf("%d", &priceperperson);

            int canstay = 0, beds;
            for(int  i = 0; i < w; i++) {
                scanf("%d", &beds);
                if (beds >= n) canstay = 1;
            }
             int currcost = n*priceperperson;
            if(currcost < b && currcost < min_cost && canstay) min_cost = currcost;
        }


        if(min_cost == INT_MAX) cout<<"stay home" <<endl;
        else cout << min_cost <<endl;
    }
    return 0;
}
