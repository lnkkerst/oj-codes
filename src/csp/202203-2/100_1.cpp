#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#define int long long

using namespace std;

struct Node {
  int t, c;
  explicit Node(int _t = 0, int _c = 0): t(_t), c(_c) {}
};

struct Ava {
  int l, r;
  explicit Ava(int _l = 0, int _r = 0): l(_l), r(_r) {}
  bool operator<(const Ava &b) const {
    if (l == b.l) {
      return r < b.r;
    } else {
      return l < b.l;
    }
  }
};

int n, m, k;
vector<Ava> a;
vector<int> ans(200011);
unordered_map<int, int> isL, isR;

signed main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    int c, t;
    cin >> t >> c;
    a.emplace_back(max(0ll, t - c + 1), t);
    isL[max(0ll, t - c + 1)]++;
    isR[t]++;
  }

  // sort(a.begin(), a.end());

  int pos = 0, now = 0;
  for (int i = 0; i <= 200010; ++i) {
    now += isL[i];
    ans[i] = now;
    now -= isR[i];
  }
  for (int i = 1; i <= m; ++i) {
    int q;
    cin >> q;
    q += k;
    cout << ans[q] << endl;
  }
  return 0;
}
