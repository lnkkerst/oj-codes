#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#define MAXN 25000010

using namespace std;

struct Edge {
    int u, v;
    double w;
} edges[MAXN];

int n, m, f[MAXN], cnt, x[5010], y[5010];
double ans;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void init(int x) {
    for(int i = 1; i <= x; ++i) f[i] = i;
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
    cin >> n;
    init(cnt);
    for(int i = 1; i <= n; ++i) {
    	cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; ++i) {
    	for(int j = i + 1; j <= n; j++) {
    		edges[++cnt].u = i;
    		edges[cnt].v = j;
    		edges[cnt].w = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    	}
    }
    init(cnt);
    sort(edges + 1, edges + 1 + cnt, cmp);
    for(int i = 1; i <= cnt; ++i) {
        if(find(edges[i].u) != find(edges[i].v)) {
            ans += edges[i].w;
            merge(edges[i].u, edges[i].v);
            ++cnt;
        }
        if(cnt == n - 1) break;
    }
    printf("%.2lf", ans);
    return 0;
}