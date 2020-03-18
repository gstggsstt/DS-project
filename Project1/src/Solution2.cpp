#include <bits/stdc++.h>

using namespace std;

// a little bit larger than 100*100 to prevent 
//    some unexpected Rumtime-errors
int a[210][210];
int S[210][210];

// Iterator counter
//   We count how many times do we call this function by some tools
//     to found out how many times do the iterators increase.
void Inc(int& x) { x++; }

int main()
{
	int n,m;
	int Sum,Max=0x80000000;
	// 0x80000000 = -2147483648 = -2^32 = int_Min

	// Input
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;Inc(i))
		for(int j=1;j<=m;Inc(j))
		{
			scanf("%d",&a[i][j]);
			// pre-calculate suffix array 'S'
			S[i][j]=a[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
		}

	for(int xi=1;xi<=n;Inc(xi))
		for(int xj=1;xj<=m;Inc(xj))
			for(int yi=xi;yi<=n;Inc(yi))
				for(int yj=xj;yj<=m;Inc(yj))
				{
					// calc sub-matrix in O(1) time
					Sum=S[yi][yj]-S[xi-1][yj]-S[yi][xj-1]+S[xi-1][xj-1];
					// update answer
					if(Sum>Max) Max=Sum;
				}
	// Output
	printf("%d\n",Max);
	return 0;
}
