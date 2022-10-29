#include <algorithm>
#include <cstdio>
#define MAXN 400010

struct mem {
  int x, y, no;
} st[MAXN];

int n, m, k, f[MAXN], q[MAXN], ans[MAXN], vis[MAXN], num;

int max(int x, int y) { return x > y ? x : y; }

bool cmp(mem a, mem b) { return a.no < b.no; }

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) {
  int t1 = find(x), t2 = find(y);
  if (t1 != t2) {
    f[t1] = t2;
    num--;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  num = n;
  for (int i = 0; i < n; ++i)
    f[i] = i;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &st[i].x, &st[i].y);
    st[i].no = 0;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &q[i]);
    vis[q[i]] = k - i;
  }
  for (int i = 0; i < m; ++i)
    st[i].no = max(vis[st[i].x], vis[st[i].y]);
  std::sort(st + 0, st + m + 0, cmp);
  for (int i = 0, j = 0; i <= k; ++i) {
    while (st[j].no == i) {
      merge(st[j].x, st[j].y);
      ++j;
    }
    ans[i] = num - (k - i);
  }
  for (int i = k; i >= 0; i--)
    printf("%d\n", ans[i]);
  return 0;
}