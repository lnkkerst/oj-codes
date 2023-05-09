#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  unordered_map<int, bool> b;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = true;
  }
  int ans = n;
  for (int i = 0; i < k; ++i) {
    int cnta = 0, cntb = 0;
    for (int j = 0; j < n; ++j) {
      if (!b[j]) {
        continue;
      }
      if (a[j][i] == a[0][i]) {
        ++cnta;
      } else {
        ++cntb;
      }
    }
    int de = cnta - cntb + 1;
    int cnt = 0;
    for (int j = 0; j < n && cnt < de; ++j) {
      if (!b[j]) {
        continue;
      }
      if (a[j][i] != a[0][i]) {
        b[j] = false;
        --ans;
        ++cnt;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
