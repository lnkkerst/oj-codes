#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1e6 + 7;
int n, t, h, r, a, b;
int c[maxn];
map<short, int> vis[10007];
int main() {
  //	freopen("tallest.in", "r", stdin), freopen("tallest.out", "w", stdout);
  cin >> n >> t >> h >> r;
  for (int i = 1; i <= r; ++i) {
    scanf("%d %d", &a, &b);
    if (a > b) {
      swap(a, b);
    }
    if (vis[a][b]) {
      continue;
    }
    vis[a][b] = true, --c[a + 1], ++c[b];
  }
  c[0] = h;
  for (int i = 1; i <= n; ++i) {
    c[i] += c[i - 1], printf("%d\n", c[i]);
  }
}
