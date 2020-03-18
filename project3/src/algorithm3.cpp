#include <bits/stdc++.h>

using namespace std;

//template of Adjacency list
template<const int _n,const int _m>// number of nodes and edges
struct Edge
{
	struct Edge_base { int to,next,w; }e[_m]; int cnt,p[_n],in[_n];
	Edge() { clear(); }
	void clear()
	{
		cnt=0,memset(p,0,sizeof(p));
		memset(in,0,sizeof(in));
	}
	void insert(const int x,const int y)
	{ e[++cnt].to=y; e[cnt].next=p[x]; p[x]=cnt; e[cnt].w=-1; in[y]++; }
	int start(const int x) { return p[x]; }
	Edge_base& operator[](const int x) { return e[x]; }
};

int n,a[110000],id[110000];
vector<int> vec;
Edge<270000,1700000> e;

// build a segment tree
void Build(const int l,const int r,const int num)
	//range [l,r], index num
{
	if(l==r)
	{
		e.insert(num,num>>1);
		id[l]=num;
		return ;
	}
	int mid=(l+r)>>1;
	Build(l,mid,num<<1);//build left sub-tree
	Build(mid+1,r,num<<1|1);// build right sub-tree
	if(e.in[num]) e.insert(num,num>>1);//connect num to its father
}

void Link(const int l,const int r,const int num,
		// current range [l,r]  index num
		const int s,const int t,const int d,const int w)
		// required range [s,t]  connect to vertex 'd' 
		// w is weight of edge,
			//is used to mark if an edge is pointing to a leaf node
{
	if(s<=l && r<=t)
	{
		e.insert(num,d);
		e[e.start(num)].w=w;
		return ;
	}
	int mid=(l+r)>>1;
	if(s<=mid) Link(l,mid,num<<1,s,t,d,w);
	//if left half contains part of required range
	if(t>mid)  Link(mid+1,r,num<<1|1,s,t,d,w);
	//if right half contains part of required range
}

void Topo_sort()
{
	typedef pair<int,int> PII;
	priority_queue<PII,vector<PII>,greater<PII> > Q;// heap
	queue<int> QQ;
	//init, find 0-in-degree-nodes
	for(int i=1;i<=n;++i)
		if(a[i]>=0 && e.in[id[i]]==0)
			Q.push(make_pair(a[i],id[i]));
	// start
	while(!Q.empty())
	{
		// each time output a node
		PII temp=Q.top(); Q.pop();
		for(int i=e.start(temp.second);i;i=e[i].next)
		{
			int tto=e[i].to;
			if(--e.in[tto]==0)
			{
				if(e[i].w>=0)Q.push(make_pair(e[i].w,tto));
				else QQ.push(tto);
			}
		}
		// clear non-leaf nodes
		while(!QQ.empty())
		{
			int tt=QQ.front(); QQ.pop();
			// for each node tt is connected to 
			for(int i=e.start(tt);i;i=e[i].next)
			{
				int tto=e[i].to;
				if(--e.in[tto]==0)
				{
					if(e[i].w>=0)Q.push(make_pair(e[i].w,tto));
					else QQ.push(tto);
				}
			}
		}
		vec.push_back(temp.first);
	} return ;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	Build(1,n,1);
	for(int i=1;i<=n;++i)
	{
		int h=a[i]%n,idd=id[i];
		if(a[i]<0) continue;
		// index+1 for index '0' is hard to deal with
		// link [h,i-1] to i
		if(i>h+1)Link(1,n,1,h+1,i-1,idd,a[i]);
		else if(i<h+1)// go back round
		{
			//link [h,n-1] to i
			Link(1,n,1,h+1,n,idd,a[i]);
			//link [0,i-1] to i
			if(i!=1)Link(1,n,1,1,i-1,idd,a[i]);
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

