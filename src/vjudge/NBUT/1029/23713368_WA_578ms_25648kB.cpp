#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

struct Node {
  string name;
  int w, v;
} a[1000010];

bool cmp(Node a, Node b) {
  return a.v > b.v;
}

void work(int n, int k) {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].name >> a[i].w >> a[i].v;
  }
  stable_sort(a + 1, a + n + 1, cmp);
  int maxx = -1, pos = 1, ans = 0, maxp;
  while (k && pos <= n) {
    if (a[pos].w <= k) {
      k -= a[pos].w;
      ans += a[pos].w * a[pos].v;
      if (maxx < a[pos].w * a[pos].v) {
        maxx = a[pos].w * a[pos].v, maxp = pos;
      }
      if (maxx == a[pos].w * a[pos].v) {
        maxx = a[pos].w * a[pos].v,
        maxp = a[pos].name < a[maxp].name ? pos : maxp;
      }
    } else {
      ans += a[pos].v * k;
      if (maxx < a[pos].v * k) {
        maxx = a[pos].v * k, maxp = pos;
      }
      if (maxx == a[pos].v * k) {
        maxx = a[pos].w * k, maxp = a[pos].name < a[maxp].name ? pos : maxp;
      }
      k = 0;
    }
    ++pos;
  }
  cout << ans << endl << a[maxp].name << ' ' << maxx << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k;
  while (cin >> n >> k) {
    work(n, k);
  }
  return 0;
}
