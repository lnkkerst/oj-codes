#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }
  vector<pair<int, int>> a{b.begin(), b.end()};
  sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second > b.second;
  });
  for (auto i : a) {
    cout << i.first << ' ' << i.second << endl;
  }
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
