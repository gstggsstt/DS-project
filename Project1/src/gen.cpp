#include <bits/stdc++.h>

using namespace std;

// seed reads from a system file to make sure RND will
//  produce different random numbers each time
random_device seed;

// mt19937 built-in random algorithm class in STL
//   this is a good algorithm, because it provide 
//   2^19937 non-repeating random numbers uniformly
//   while rand() can only provide about 1e9 non-repeating numbers
// Note: Add -std=c++11 to the end of compiling command
mt19937	RND(seed());

int main(int argv,char ** argc)
{
	// If argv < 3 then exit the program
	assert(argv>=3);

	//argc[0] == work directory
	int n=atoi(argc[1]);
	int m=atoi(argc[2]);
	int lim=atoi(argc[3]);

	// Out put n and m
	cout << n << ' ' << m << endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			// transform (unsigned int) to (int) will change numbers
			//   which are greater than 2147483647 into negative numbers
			//   therefore, half positive numbers will change 
			cout << (int)RND()%lim << ' ';
		//new line
		cout << endl;
	}
	
	return 0;
}
