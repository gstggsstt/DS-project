#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
priority_queue<PII,vector<PII>, greater<PII> > Q;
vector<int> vec;

int n,a[1100],cnt;
bool taken[1100];

void check()
{
	//check the whole array
	for(int i=0;i<n;++i)
	{
		//bad point continue
		if(a[i]<0 || taken[i])continue;
		int j; for(j=a[i]%n;j!=i;j=(j+1)%n)
			// must be taken away not empty at the beginning
			if(a[j]!=-2)break;
		// good point, ready to print
		// make a pair recording number and position
		if(j==i) Q.push(make_pair(a[i],i)),taken[i]=true;
	} return ;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		// -1 represents empty
		if(a[i]>=0)cnt++;
		else a[i]=-1;
	}
	while(cnt--)
	{
		check();
		if(Q.empty()) break;
		PII temp=Q.top(); Q.pop();
		// save answer
		if(temp.first>=0)vec.push_back(temp.first);
		a[temp.second]=-2;
	}
	
	//output
	if(vec.size())printf("%d",vec[0]);
	for(int i=1;i<(int)vec.size();++i)
		printf(" %d",vec[i]);
	printf("\n");
	return 0;
}
