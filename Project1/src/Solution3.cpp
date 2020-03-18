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
	scanf("%d%d",&n,&m);
	// 0x80000000 = -2147483648 = -2^32 = int_Min

	// Input
	for(int i=1;i<=n;Inc(i))
		for(int j=1;j<=m;Inc(j))
		{
			scanf("%d",&a[i][j]);
			// the suffix array for each column
			S[i][j]=S[i-1][j]+a[i][j];
		}

	for(int x=1;x<=n;Inc(x))
	for(int y=x;y<=n;Inc(y))
	{
		Sum=0;
		// DP(Dynamic Programing) by row
		for(int i=1;i<=m;Inc(i))
		{
			// compare two cases : Sum>=0, Sum<0
			Sum+=S[y][i]-S[x-1][i];
			if(Sum<0)Sum=0;
			// update answer
			if(Sum>Max)Max=Sum;
		}
	}
	
	// Output
	printf("%d\n",Max);
	return 0;
}
