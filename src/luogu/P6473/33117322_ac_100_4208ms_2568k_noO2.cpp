#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int n, len, v;
  cin >> n >> len >> v;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = 1;
  sort(a.begin() + 1, a.end(), greater<int>());
  for (int i = 1; i < (int)a.size(); ++i)
    a[i] += a[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    vector<int>::iterator ans = upper_bound(a.begin(), a.end(), t * v - len);
    if (ans == a.end())
      cout << -1 << endl;
    else
      cout << distance(a.begin(), ans) << endl;
  }
  return 0;
}