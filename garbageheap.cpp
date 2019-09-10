#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {


	int t; scanf("%d", &t);
	while (t--) {
		int A,B,C; cin>>A>>B>>C;
    long long m[A][B][C];
    for (int i=0;i<A;++i) for (int j=0;j<B;++j) for (int k=0;k<C;++k) {
      long long g; cin>>g;
      // greater than zero means value is memoized
      if (i>0) g+=m[i-1][j][k];
      if (j>0) g+=m[i][j-1][k];
      if (k>0) g+=m[i][j][k-1];
      if (i>0 && j>0) g-=m[i-1][j-1][k];
      if (j>0 && k>0) g-=m[i][j-1][k-1];
      if (i>0 && k>0) g-=m[i-1][j][k-1];
      if (i>0 && j>0 && k>0) g+=m[i-1][j-1][k-1];
      m[i][j][k]=g;
    }

    // try all possible cubes,
    // first three loops represent the starting corner and last three represent the ending corner

    long long max_sum = INT_MIN;
    for (int i=0;i<A;++i) for (int j=0;j<B;++j) for (int k=0;k<C;++k)
    for (int i1=i;i1<A;++i1) for (int j1=j;j1<B;++j1) for (int k1=k;k1<C;++k1)  {
      long long s = m[i1][j1][k1];
      if (i>0) s-=m[i-1][j1][k1];
      if (j>0) s-=m[i1][j-1][k1];
      if (k>0) s-=m[i1][j1][k-1];
      if (i>0 && j>0) s+=m[i-1][j-1][k1];
      if (j>0 && k>0) s+=m[i1][j-1][k-1];
      if (i>0 && k>0) s+=m[i-1][j1][k-1];
      if (i>0 && j>0 && k>0) s-=m[i-1][j-1][k-1];
      if (s>max_sum) max_sum = s;
    }

    cout<<max_sum<<endl;
    if (t) cout<<endl;
	}
	return 0;
}
