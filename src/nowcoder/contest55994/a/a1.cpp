#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0, ye = 0, cnt = 0;
  for (auto i : s) {
    int x = i - '0';
    if ((x >> 1) & 1) {
      ++ans;
      continue;
    }
    if (x & 1) {
      ++ye;
      continue;
    }
    if (ye) {
      ++ans;
      --ye;
      continue;
    }
  }
  cout << ans + (ye / 2) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
