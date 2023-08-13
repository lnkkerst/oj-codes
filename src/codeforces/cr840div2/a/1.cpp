#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b(32);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int i = 0; i < 12; ++i) {
      b[i] += (x >> i) & 1;
    }
    a.emplace_back(x);
  }
  int mi = 0;
  for (int i = 0; i < 12; ++i) {
    if (b[i] == n) {
      mi |= (1 << i);
    }
  }
  int ma = 0;
  for (int i = 0; i < 12; ++i) {
    if (b[i]) {
      ma |= (1 << i);
    }
  }
  cout << ma - mi << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
