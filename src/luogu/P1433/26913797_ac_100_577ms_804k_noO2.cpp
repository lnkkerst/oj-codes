#include <cmath>
#include <cstdio>
#include <cctype>

int n;
bool vis[2333];
double x[233], y[233];
double dis[2333][2333];
double ans = 1e9;

int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

double min(double x, double y) {return x < y ? x : y; }

void dfs(int step, int now, double sum) {
    if(sum > ans) return ;
    if(step == n) {
        ans = min(ans, sum);
        return ;
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) {
            vis[i] = 1;
            dfs(step + 1, i, sum + dis[now][i]);
            vis[i] = 0;
        }
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i)
        scanf("%lf%lf", &x[i], &y[i]);
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dis[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    dfs(0, 0, 0);
    printf("%.2lf", ans);
    return 0;
}