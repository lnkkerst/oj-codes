#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> b;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    b[x] = i;
  }
  int ans = 0;
  for (auto i : b) {
    if (i.first - i.second) {
      ans = gcd(abs(i.first - i.second), ans);
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
