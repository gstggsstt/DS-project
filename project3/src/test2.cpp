#include <bits/stdc++.h>

using namespace std;

int main()
{
	char S[100],cmd[100],T[100];
	int n;
	printf("Program1:\t");
	scanf("%s",S);
	printf("Program2:\t");
	scanf("%s",T);
	printf("N:\t");
	scanf("%d",&n);
	srand(time(0));

	do
	{
		sprintf(cmd,"gen2 %d %d >in.txt",n,rand());
		system(cmd);
		sprintf(cmd,"%s <in.txt >out.txt",S);
		system(cmd);
		sprintf(cmd,"%s <in.txt >out1.txt",T);
		system(cmd);
		sprintf(cmd,"fc /w out.txt out1.txt");
	}while(!system(cmd));

	system("pause");

	return 0;
}
