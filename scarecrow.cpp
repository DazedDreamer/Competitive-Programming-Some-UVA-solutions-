#include <cstdio>

using namespace std;

int main(){
    int t,n;
    char s[100];

    scanf("%d",&t);

    for(int i = 1;i <= t;++i){
        scanf("%d %s",&n,s);

        int ans = 0;

        for(int i = 0;i < n;){
            if(s[i] == '#') ++i;
            else{
                ++ans;
                i += 3;
            }
        }

        printf("Case %d: %d\n",i,ans);
    }

    return 0;
}
