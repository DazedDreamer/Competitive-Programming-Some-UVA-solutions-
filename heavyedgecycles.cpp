#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct d_node
{
	int point1;
	int point2;
	int weight;
}enode;
enode edge[25005];

//union_set
int sets[1001];
int ranks[1001];

void set_inital( int a, int b )
{
	for ( int i = a ; i <= b ; ++ i ) {
		ranks[i] = 0;
		sets[i] = i;
	}
}

int  set_find( int a )
{
	if ( a != sets[a] )
		sets[a] = set_find( sets[a] );
	return sets[a];
}

void set_union( int a, int b )
{
	if ( ranks[a] < ranks[b] )
		sets[a] = b;
	else {
		if ( ranks[a] == ranks[b] )
			ranks[a] ++;
		sets[b] = a;
	}
}
//end_union_set

int cmp_e( enode a, enode b )
{
	return a.weight < b.weight;
}

int kruskal( int n, int m )
{
	sort( edge, edge+m, cmp_e );

	set_inital( 0, n );
	int sum = 0;
	for ( int i = 0 ; i < m ; ++ i ) {
		int A = set_find( edge[i].point1 );
		int B = set_find( edge[i].point2 );
		if ( A != B )
			set_union( A, B );
		else {
			if ( sum ++ ) printf(" ");
			printf("%d",edge[i].weight);
		}
	}
	return sum;
}

int main()
{
	int n,m,a,b,c;
	while ( scanf("%d%d",&n,&m) && n+m ) {
		for ( int i = 0 ; i < m ; ++ i ) {
			scanf("%d%d%d",&a,&b,&c);
			edge[i].point1 = a;
			edge[i].point2 = b;
			edge[i].weight = c;
		}

		if ( !kruskal( n, m ) )
			printf("forest");
		printf("\n");
	}
	return 0;
}
