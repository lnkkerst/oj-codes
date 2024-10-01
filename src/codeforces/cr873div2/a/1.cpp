#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << i * 2 << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
