#pragma GCC optimize(2)
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
  sort(a.begin(), a.end());
  if (a.front() % 2 == 0) {
    for (auto i : a) {
      if (i & 1) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }
  cout << "YES" << endl;
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
