#pragma GCC optimize(2)
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main() {
  int n, d;
  cin >> n >> d;
  int ansk = -1, ansx = -1;
  for (int k = 2; k <= 23333333; ++k) {
    vector<int> s;
    int t = n;
    while (t) {
      s.push_back(t % k);
      t /= k;
    }
    int tmp = 0;
    for (auto i : s) {
      if (i != d) {
        break;
      }
      ++tmp;
    }
    if (tmp > ansx) {
      ansk = k;
      ansx = tmp;
    }
  }
  cout << ansk << ' ' << ansx;
  return 0;
}
