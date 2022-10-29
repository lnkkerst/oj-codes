#include <cstdio>
#define N 400010
#define int long long
int cov[N], sum[N];
int n, m, t, l, r, x;
int a[N];
void pushdown(int cur, int len) {
  cov[cur << 1] += cov[cur];
  cov[cur << 1 | 1] += cov[cur];
  sum[cur << 1] += cov[cur] * ((len + 1) >> 1);
  sum[cur << 1 | 1] += cov[cur] * (len >> 1);
  cov[cur] = 0;
}
void update(int cur) { sum[cur] = sum[cur << 1] + sum[cur << 1 | 1]; }
int query(int l, int r, int L, int R, int cur) {
  if (l >= L && r <= R)
    return sum[cur];
  if (cov[cur])
    pushdown(cur, r - l + 1);
  int mid = l + r >> 1, ans = 0;
  if (L <= mid)
    ans += query(l, mid, L, R, cur << 1);
  if (R > mid)
    ans += query(mid + 1, r, L, R, cur << 1 | 1);
  return ans;
}
void add(int l, int r, int L, int R, int x, int cur) {
  if (l >= L && r <= R) {
    cov[cur] += x;
    sum[cur] += (r - l + 1) * x;
    return;
  }
  if (cov[cur])
    pushdown(cur, r - l + 1);
  int mid = l + r >> 1;
  if (L <= mid)
    add(l, mid, L, R, x, cur << 1);
  if (R > mid)
    add(mid + 1, r, L, R, x, cur << 1 | 1);
  update(cur);
}
#undef int
int main() {
#define int long long
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    add(1, n, i, i, a[i], 1);
  }
  while (m--) {
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld%lld%lld", &l, &r, &x);
      add(1, n, l, r, x, 1);
    } else {
      scanf("%lld%lld", &l, &r);
      printf("%lld\n", query(1, n, l, r, 1));
    }
  }
  return 0;
}