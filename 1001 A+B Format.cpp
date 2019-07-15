#include <bits/stdc++.h>

using namespace std;
int main()
{
	int a, b,c;
	string aus{};
	c=scanf("%d %d",&a,&b);
	c = a + b;
	if (c < 0) { c = -c; printf("-"); }
	aus = to_string(c);
	c = aus.size();
	for (int i = c; i >0; --i) 
	{
		if ((i % 3 == 0)&&(i!=c)) printf(",");
		printf("%c",aus[c-i]);
	}
	return 0;
}