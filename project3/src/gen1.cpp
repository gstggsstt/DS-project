#include <bits/stdc++.h>

using namespace std;

int h[110000],a[110000];


int main(int argv,char ** argc)
{
	FILE* out=fopen("ans.txt","w");
	map<int,int> Map;
	assert(argv>=2);
	int sd=(argv>=3?atoi(argc[2]):time(0));
	mt19937 RND(sd);
	int n=atoi(argc[1]);
	int m=RND()%(n/5)+(n*4/5);
	for(int i=1;i<=m;++i)
	{
		do{ a[i]=RND()%(n*10)+1; }while(Map[a[i]]);
		Map[a[i]]=1;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i)
	{
		int k;
		for(k=0;h[(a[i]+k)%n];++k);
		h[(a[i]+k)%n]=a[i];
	}
	printf("%d\n",n);
	for(int i=0;i<n;++i)
		printf("%d ",h[i]?h[i]:-1);
	printf("\n");
	for(int i=1;i<=m;++i)
		fprintf(out,"%d ",a[i]);
	printf("\n");
	return 0;
}


