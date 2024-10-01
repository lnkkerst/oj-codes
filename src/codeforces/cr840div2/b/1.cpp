#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node {
  int first;
  int second;
  bool operator<(const Node &b) const {
    return this->first < b.first;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  multiset<int> b;
  vector<Node> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    int h;
    cin >> h;
    a[i] = Node{h, -1};
  }
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    a[i].second = p;
    b.insert(p);
  }
  sort(a.begin() + 1, a.end());
  // cout << "ok" << endl;
  int pos = 1;
  int dm = 0;
  while (!a.empty()) {
    if (k <= 0) {
      cout << "NO" << endl;
      return;
    }
    dm += k;
    auto it = upper_bound(a.begin(), a.end(), Node{dm, 0});
    if (it == a.end()) {
      cout << "YES" << endl;
      return;
    }
    auto ed = it - a.begin();
    for (auto i = a.begin() + pos; i != it; ++i) {
      // cout << i - a.begin() << endl;
      auto tmpit = b.find(i->second);
      b.erase(tmpit);
    }
    pos = ed;
    k -= *b.begin();
  }
  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
