#include "bits/stdc++.h"

using namespace std;

int main()
{
	string aus;
	string num[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	array<int, 4> digit{};
	int n = 0;
	int i;
	getline(cin, aus);
	for (auto au : aus)
		n += au - '0';
	if (n == 0)printf("zero");
	else
	{
		for(i=0;n>0;++i,n/=10)
		{
			digit[i] = n%10;
		}
		for(auto x=i-1;x>=0;--x)
		{
			cout<<num[digit[x]];
			if (x != 0)printf(" ");
		}
	}
	return 0;
}
