#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    int n = rods.size();
    int tot = accumulate(rods.begin(), rods.end(), 0);
    map<int, vector<int>> b;
    for (int i = 1; i < (1 << n); ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          cnt += rods[j];
        }
      }
      b[cnt].emplace_back(i);
    }
    vector<pair<int, vector<int>>> a{b.begin(), b.end()};
    reverse(a.begin(), a.end());
    for (auto [k, v] : a) {
      if (v.size() <= 1) {
        continue;
      }
      cout << v.size() << endl;
      shuffle(v.begin(), v.end(), mt19937{random_device{}()});
      for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
          if (!(v[i] & v[j])) {
            return k;
          }
        }
      }
    }
    return 0;
  }
};
