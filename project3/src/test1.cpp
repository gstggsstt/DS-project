#include <bits/stdc++.h>

using namespace std;

int main()
{
	char S[100],cmd[100];
	int n;
	printf("Program:\t");
	scanf("%s",S);
	printf("N:\t");
	scanf("%d",&n);
	srand(time(0));

	do
	{
		sprintf(cmd,"gen1 %d %d >in.txt",n,rand());
		system(cmd);
		sprintf(cmd,"%s <in.txt >out.txt",S);
		system(cmd);
		sprintf(cmd,"fc /w ans.txt out.txt");
	}while(!system(cmd));

	system("pause");

	return 0;
}
