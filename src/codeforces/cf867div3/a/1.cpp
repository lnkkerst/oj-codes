#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  auto b = a;
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  int ans = -2;
  for (int i = 0; i < n; ++i) {
    if (a[i] + i <= t) {
      if (ans == -2) {
        ans = i;
      } else if (b[i] > b[ans]) {
        ans = i;
      }
    }
  }
  cout << ans + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
