#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
int q,a[MAXN], n;
#define foreach(i, a, b) for(int i = (a);i <= (b);++i)
int lowbit(int x) { return x & (-x); }
void add(int x, int val) {
  for (; x <= n; x += lowbit(x)) {
    a[x] += val;
  }
}
int query(int x) {
  int ret = 0;
  for (; x; x -= lowbit(x)) {
    ret += a[x];
  }
  return ret;
}
int query(int l, int r) { return query(r) - query(l - 1); }
int main() {
  scanf("%d%d", &n,&q);
  foreach(i, 1, n) {
    int x;
    scanf("%d", &x);
    add(i, x);
  }
  int opt;
  int a, b;
  while (q--) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &a, &b);
      add(a, b);
    } else {
      scanf("%d%d", &a, &b);
      printf("%d\n", query(a, b));
    }
  }
  return 0;
}