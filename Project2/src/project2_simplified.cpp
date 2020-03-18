#include <bits/stdc++.h>
using namespace std;
struct Node { int data,l,r; }S[1100];
int a[1100],cnt;
void Dfs(const int x)
{
	if(~S[x].l) Dfs(S[x].l);
	S[x].data=a[cnt++];
	if(~S[x].r) Dfs(S[x].r);
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		S[i].l=x; S[i].r=y;
	}

	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n); Dfs(0);
	queue<int> Q; Q.push(0);
	while(!Q.empty())
	{
		int temp=Q.front(); Q.pop();
		printf("%d ",S[temp].data);
		if(~S[temp].l) Q.push(S[temp].l);
		if(~S[temp].r) Q.push(S[temp].r);
	}
	printf("\n");
	return 0;
}

