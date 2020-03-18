#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,lim;
	scanf("%d%d",&n,&lim);
	srand(time(0));
	while(true)
	{
		char str[110];
		sprintf(str,"gen %d %d %d >in.txt",n,lim,rand());
		system(str);
		system("project2 0 <in.txt >out.txt");
		if(system("fc out.txt ans.txt")) break;
		else printf("Accepted!\n");
	}
	return 0;
}
