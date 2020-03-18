#include <bits/stdc++.h>

using namespace std;

//template of Adjacency list
template<const int _n,const int _m>// number of nodes and edges
struct Edge
{
	struct Edge_base { int to,next; }e[_m]; int cnt,p[_n],in[_n];
	Edge() { clear(); }
	void clear()
	{
		cnt=0,memset(p,0,sizeof(p));
		memset(in,0,sizeof(in));
	}
	void insert(const int x,const int y)
	{ e[++cnt].to=y; e[cnt].next=p[x]; p[x]=cnt; in[y]++; }
	int start(const int x) { return p[x]; }
	Edge_base& operator[](const int x) { return e[x]; }
};

int n,a[1100],id[1100];
vector<int> vec;
Edge<1100,1100000> e;

void Topo_sort()
{
	typedef pair<int,int> PII;
	priority_queue<PII,vector<PII>,greater<PII> > Q; // heap
	//init, find 0-in-degree-nodes
	for(int i=1;i<=n;++i)
		if(a[i]>=0 && e.in[i]==0)
			Q.push(make_pair(a[i],i));
	// start
	while(!Q.empty())
	{
		// each time output a node
		PII temp=Q.top(); Q.pop();
		for(int i=e.start(temp.second);i;i=e[i].next)
			if(--e.in[e[i].to]==0)
				Q.push(make_pair(a[e[i].to],e[i].to));
		if(temp.first>=0) vec.push_back(temp.first);
	} return ;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);

	for(int i=1;i<=n;++i)
	{
		if(a[i]<0) continue;
		// index+1 for index '0' is hard to deal with
		// link [h,i-1] to i
		if(i>a[i]%n+1)
			for(int j=a[i]%n+1;j<i;++j) e.insert(j,i);
		if(i<a[i]%n+1)// go back round
		{
			//link [h,n-1] to i
			for(int j=a[i]%n+1;j<=n;++j) e.insert(j,i);
			//link [0,i-1] to i
			for(int j=1;j<i;++j) e.insert(j,i);
		}
	}

	Topo_sort();

	// output answer
	if(vec.size())printf("%d",vec[0]);
	for(int i=1;i<(int)vec.size();++i)
		printf(" %d",vec[i]);

	printf("\n");

	return 0;
}

