#include "bits/stdc++.h"


using namespace std;

const int INF {0x3fffff};
const int MAXV = 510;

int n{};
int m{};
int st{};
int ed{};
array<int, MAXV>weight{};
//array<array<int, MAXV>, MAXV>g{0};
int g[MAXV][MAXV];
array<int, MAXV> d{};
array<int, MAXV> w{};
array<int, MAXV> num{};
array<bool, MAXV> vis{false};

void Dijkstra(int s)
{
	d.fill(INF);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for(auto i=0;i<n;++i)
	{
		int u = -1,MIN = INF;
		for(int j=0;j<n;++j)
		{
			if(false==vis[j]&& d[j]<MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)return;
		vis[u] = true;
		for(int v=0;v<n;v++)
		{
			if(false==vis[v]&&g[u][v]!=INF)
			{
				if(d[u]+g[u][v]<d[v])
				{
					d[v] = d[u] + g[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + g[u][v] == d[v])
				{
					if (w[u] + weight[v] > w[v])
					{
							w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}

	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(auto i=0;i<n;++i)
	{
		scanf("%d",&weight[i]);
	}
	int u, v;
	fill(g[0],g[0]+MAXV*MAXV,INF);
	for(auto i=0;i<m;++i)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&g[u][v]);
		g[v][u] = g[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
}
