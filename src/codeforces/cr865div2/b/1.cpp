#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  array<vector<int>, 2> a;
  a[0].resize(n);
  a[1].resize(n);
  for (int i = 0; i < n; ++i) {
    a[!(i & 1)][i] = i + 1;
  }
  a[0][0] = n * 2;
  for (int i = 1; i < n; ++i) {
    a[(i & 1)][i] = n + i;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[0][i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[1][i] << ' ';
  }
  cout << endl;
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
