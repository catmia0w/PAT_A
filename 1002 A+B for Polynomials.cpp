#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, m, x = 0;
	double temp;
	array<double, 1005> a = {};
	x = scanf("%d", &n);
	for (auto i = 0; i < n; ++i)
	{
		x = scanf("%d", &m);
		x = scanf("%lf", &a[m]);
	}
	x=scanf("%d", &n);
	for (auto i = 0; i < n; ++i)
	{
		x = scanf("%d", &m);
		x = scanf("%lf", &temp);
		a[m] += temp;
	}
	n = 0;
	for (auto i = 0; i < 1001; ++i)
	{
		if (a[i] != 0)++n;
	}
	printf("%d", n);
	for (auto i = 1000; i >= 0; --i)
	{
		if (a[i] != 0)
		{
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}