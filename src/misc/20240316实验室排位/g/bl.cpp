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

  int n = 100000;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      auto si = to_string(i);
      auto sj = to_string(j);
      reverse(si.begin(), si.end());
      reverse(sj.begin(), sj.end());
      int ri = stoi(si);
      int rj = stoi(sj);
      // if (i == ri && j == rj) {
      //   continue;
      // }
      // if (i == rj && j == ri) {
      //   continue;
      // }
      if (i * j == ri * rj) {
        cout << i << ' ' << j << endl;
      }
    }
  }
}
