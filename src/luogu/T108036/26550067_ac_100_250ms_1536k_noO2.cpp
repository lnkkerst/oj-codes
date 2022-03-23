#include<cmath>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 998244353;
const int maxn = 1e5 + 1;
int n, m;
int num, cnt;
int a[maxn];
int d[2][maxn];
inline void Sep(int x)
{
	for(int i = 1; (long long) i * i <= x; ++i)
		if(!(x % i))
		{
			++cnt;
			if(i * i != x) ++cnt;
		}
	for(int i = 2; (long long) i * i <= x; ++i)
		if(!(x % i))
		{
			++num;
			while(!(x % i)) x /= i, ++a[num];
		}
	if(x != 1) ++a[++num];
}
inline int Pow(int x, int n)
{
	int sum = 1;
	while(n)
	{
		if(n & 1) sum = (long long) sum * x % mod;
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return sum;
}
int main()
{
//	freopen("count.in", "r", stdin), freopen("count.out", "w", stdout);
	scanf("%d %d", &n, &m);
	Sep(n);
	int ans = 1;
	for(int x = 1; x <= num; ++x)
	{
		int now = 1, last = 0;
		memset(d, 0, sizeof(d));
		d[0][0] = 1;
		for(int i = 1; i <= (m << 1); ++i)
		{
			for(int j = 0; j <= m * a[x]; ++j) d[now][j] = 0;
			for(int j = 0; j <= m * a[x]; ++j)
			{
				for(int k = 0; k <= min(j, a[x]); ++k)
				{
					d[now][j] += d[last][j - k];
					if(d[now][j] >= mod) d[now][j] -= mod;
				}
			}
			swap(now, last);
		}
		ans = (long long) ans * d[last][a[x] * m] % mod;
	}
	printf("%d", ((long long) Pow(cnt, m << 1) + ans % mod) * Pow(2, mod - 2) % mod);
}