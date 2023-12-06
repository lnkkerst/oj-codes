#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define int long long

priority_queue<pair<int, int>> q;
int n, m, k;
vector<int> t, c;

bool check(int d) {
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i] > d) {
      tot += c[i] * (t[i] - d);
    }
  }
  return tot <= m;
}

signed main() {
  cin >> n >> m >> k;
  t.resize(n + 1);
  c.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> c[i];
  }
  int l = k, r = 2e10;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}
