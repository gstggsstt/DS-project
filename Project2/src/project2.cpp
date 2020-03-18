#include <bits/stdc++.h>

//#define Debug

//  Add this line if 0 is not root
//#define RootNot0

using namespace std;

//  Node of tree
//    'data' is the value stored on the node
//    'l' is the index of left child
//    'r' is the index of right child
//    global variable will be initialized by 0
struct Node { int data,l,r; }S[1100];

//  'a' is the array to sort elements
//  'cnt' is a counter to fill sorted elements into the tree one by one
int a[1100],cnt;

//  If Child[x] is 
//    true:  x is a child of certain node
//    false: x is root
//  There will be only one node whose Child[x] is false, 
//    and this node is root of the tree.
bool Child[1100];

//  Fill sorted numbers into nodes
void Dfs(const int x)
{
	//  Note: 'if(~x)' is equal to 'if(x!=-1)'
	//    for only ~(-1)==0

#ifdef Debug
	if(~S[x].l)printf("%3d --LEFT---> %3d\n",x,S[x].l);
#endif
	//  Fill left sub-tree first.
	if(~S[x].l) Dfs(S[x].l);
	//  Fill node x itself.
	S[x].data=a[cnt++];
#ifdef Debug
	if(~S[x].r)printf("%3d --RIGHT--> %3d\n",x,S[x].r);
#endif
	//  Fill right sub-tree in the end.
	if(~S[x].r) Dfs(S[x].r);
}

int main(int argv, char ** argc)
{
	int n,x,y,Root=0;

	//  Read 'n'
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		//  Read n pairs of numbers
		scanf("%d%d",&x,&y);
		//  Link the tree by index
		S[i].l=x; S[i].r=y;

		//  Note: 'if(~x)' is equal to 'if(x!=-1)'
		//    for only ~(-1)==0

#ifdef RootNot0
		//  Mark x,y as children
		if(~x)Child[x]=true;
		if(~y)Child[y]=true;
#endif
	}

#ifdef RootNot0
	//  Find out root
	//  If 'i' is not root then Child[i]==true
	for(int i=0;i<n;++i)
		if(!Child[i]) { Root=i; break; }
#endif

	//  Input n numbers
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	//  Sort by increasing order
	sort(a,a+n);

	//  Deep-First-Search
	//  Fill the numbers by Inorder traversal
	Dfs(Root);

	//  Bfs, Breadth-First-Search 
	//  Print the tree by the order of node depth

	//  STL queue
	queue<int> Q; Q.push(Root);
	while(!Q.empty())
	{
		//  Pop first element from queue
		int temp=Q.front(); Q.pop();
		//  Print the node
		printf("%d ",S[temp].data);

		//  Note: 'if(~x)' is equal to 'if(x!=-1)'
		//    for only ~(-1)==0
		
		//  Push left child
		if(~S[temp].l) Q.push(S[temp].l);
		//  Push right child
		if(~S[temp].r) Q.push(S[temp].r);
	}

	//  Printing a new line in the end is a good habit.
	printf("\n");

	if(argv==1)system("pause");
	//  End
	return 0;
}

