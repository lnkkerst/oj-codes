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
  vector<int> b;
  b.emplace_back(a.front());
  for (auto i : a) {
    if (i != b.back()) {
      b.emplace_back(i);
    }
  }
  if (b.size() <= 2) {
    cout << b.size() << endl;
    return;
  }
  vector<int> c;
  c.emplace_back(b[0]);
  c.emplace_back(b[1]);
  for (int i = 2; i < b.size(); ++i) {
    int a1 = c[c.size() - 2];
    int a2 = c[c.size() - 1];
    int a3 = b[i];
    if ((a1 > a2 && a2 > a3) || (a1 < a2 && a2 < a3)) {
      c.pop_back();
    }
    c.emplace_back(a3);
  }
  cout << c.size() << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
