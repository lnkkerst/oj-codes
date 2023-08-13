#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> a1(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a1[i];
  }
  int l = 1, r = n;
  while (a[l] == a1[l]) {
    ++l;
  }
  while (a[r] == a1[r]) {
    --r;
  }
  while (l != 1 && a1[l - 1] <= a1[l]) {
    --l;
  }
  while (r != n && a1[r + 1] >= a1[r]) {
    ++r;
  }
  cout << max(1, l) << ' ' << min(n, r) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
