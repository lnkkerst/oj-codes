#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  reverse(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    while (a[i] >= a[i - 1]) {
      if (!a[i] && !a[i - 1]) {
        cout << "-1" << endl;
        return;
      }
      a[i] >>= 1;
      ++ans;
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
