#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int>> a;
vector<bool> b;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(r, l));
  }
  sort(a.begin(), a.end());
  b.reserve(n - 1);
  for (int i = 0; i < n; ++i) {
    if (!b[i]) {
      ++ans;
      b[i] = 1;
      for (int j = i + 1; j < n; ++j)
        if (a[i].first > a[j].second)
          b[j] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}