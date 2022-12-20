#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!a.empty() && a.back() != x) {
      a.emplace_back(x);
    }
    if (a.empty()) {
      a.emplace_back(x);
    }
  }
  if (a.size() == 1) {
    cout << 0 << endl;
    return;
  }
  if (a.size() == 2) {
    if (a[0] <= a[1]) {
      cout << 0 << endl;
    } else {
      cout << a[0] << endl;
    }
    return;
  }
  int ansl = 0, ansr = a[0];
  if (a[1] < a[0]) {
    ansl = (a[0] + a[1] + 1) / 2;
    ansr = 1e9;
  } else {
    ansl = 0;
    ansr = (a[0] + a[1]) / 2;
  }
  for (int i = 2; i < a.size(); ++i) {
    if (a[i] < a[i - 1]) {
      ansl = max(ansl, (a[i] + a[i - 1] + 1) / 2);
    } else {
      ansr = min(ansr, (a[i] + a[i - 1]) / 2);
    }
    if (ansl > ansr) {
      cout << -1 << endl;
      return;
    }
  }
  cout << ansl << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
