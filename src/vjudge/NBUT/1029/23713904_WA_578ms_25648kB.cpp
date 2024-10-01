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
  sort(a + 1, a + n + 1, cmp);
  int maxx = -1, maxp = 1, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (k <= 0) {
      break;
    }
    int val = min(a[i].w, k) * a[i].v;
    k -= a[i].w, ans += val;
    if (maxx < val || (maxx == val) && a[maxp].name > a[i].name) {
      maxx = val, maxp = i;
    }
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
