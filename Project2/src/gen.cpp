#include <bits/stdc++.h>

using namespace std;

// Data array
int a[1100];
// Counter for node allocate
int cnt;

// Tree node struct
struct node { int n,l,r; }T[1100];

// Insert x into sub-tree S
void Insert(const int S,const int x)
{
	// If x < current data goto left
	if(x<T[S].n)
	{
		// If there is no left child, allocate a new one
		if(!T[S].l) T[S].l=++cnt,T[cnt]=(node){x,0,0};
		// Insert recursively
		else Insert(T[S].l,x);
	}
	// If x >= current data goto Right
	else
	{
		// If there is no right child, allocate a new one
		if(!T[S].r) T[S].r=++cnt,T[cnt]=(node){x,0,0};
		// Insert recursively
		else Insert(T[S].r,x);
	}
}

int main(int argv,char ** argc)
{
	FILE* ans = fopen("ans.txt","w");
	// Input n and number-max-limit
	int n,lim,seed=0;
	if(argv>=4)
	{
		n=atoi(argc[1]);
		lim=atoi(argc[2]);
		seed=atoi(argc[3]);
	}
	else scanf("%d %d",&n,&lim);

	if(!seed)srand(time(0));
	else srand(seed);

	// Get random array
	for(int i=1;i<=n;++i) a[i]=rand()*rand()%lim;

	// Creat a BST
	T[++cnt]=(node){a[1],0,0};
	for(int i=2;i<=n;++i) Insert(1,a[i]);

	// Print Answer, BFS output node data
	queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int temp=Q.front(); Q.pop();
		if(T[temp].l) Q.push(T[temp].l);
		if(T[temp].r) Q.push(T[temp].r);
		fprintf(ans,"%d ",T[temp].n);
	}
	fprintf(ans,"\n");
	fclose(ans);


	// Output sample input//
	printf("%d\n",n);
	for(int i=1;i<=n;++i)
		printf("%d %d\n",T[i].l-1,T[i].r-1);

	for(int i=1;i<=n;++i)
		swap(a[rand()%n+1],a[rand()%n+1]);

	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	printf("\n");
	////////////////////////

	if(argv==1)system("pause");

	return 0;
}
