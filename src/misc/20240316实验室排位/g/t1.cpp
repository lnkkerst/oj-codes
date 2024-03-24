#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b;
  map<int, int> bk;
  while (cin >> a >> b) {
    ++bk[a];
  }

  for (auto [k, v] : bk) {
    cout << k << ' ' << v << endl;
  }
}
