#include <cstdio>
#define MAXN 500001

int main() {
	int map[MAXN], n, m, s, u[MAXN], v[MAXN], w[MAXN], dis[MAXN];
	const int inf = 999999999;
	
	scanf("%d%d%d", &n, &m, &s);
	
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		
	for(int i = 1; i <= n; i++)
		dis[i] = inf;
	
	dis[s] = 0;
	
	for(int k = 1; k <= n - 1; k++)
		for(int i = 1; i <= m; i++)
			if(dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
	
	for(int i = 1; i <= n; i++)
		printf("%d ", dis[i]);
		
	return 0;
	
}