#include "bits/stdc++.h"

using namespace std;

vector<int> g[100]{};
array<int, 100>leaf;
int max_h{ -1 };

void dfs(int index,int h)
{
	max_h = max(max_h,h);
	if(0==g[index].size())
	{
		leaf[h]++;
		return;
	}
	for(auto i=0;i<g[index].size();++i)
		dfs(g[index][i],h+1);
}

int main()
{
	int n{}, m{};
	int parent{}, child{};
	int num{};
	scanf("%d %d",&n,&m);

	for(auto i=0;i<m;++i)
	{
		scanf("%d %d",&parent,&num);
		for (auto j = 0; j < num; ++j)
		{
			scanf("%d", &child);
			g[parent].push_back(child);
		}
	}
	dfs(1,0);
	printf("%d",leaf[0]);
	for (auto i = 1; i <= max_h; ++i)
		printf(" %d",leaf[i]);
	return 0;
}