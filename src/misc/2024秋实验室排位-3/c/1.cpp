#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

constexpr double EPS = 1e-9;

void solve() {
  int n;
  cin >> n;
  using pii = pair<int, int>;
  vector<pii> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  auto pow2 = [&](int x) {
    return x * x;
  };
  auto dis2 = [&](pii a, pii b) {
    return pow2(a.first - b.first) + pow2(a.second - b.second);
  };
  int age = n;
  using Element = tuple<double, int, int>;
  priority_queue<Element, vector<Element>, function<bool(Element, Element)>> h(
    [&](Element a, Element b) -> bool {
      auto [ldis, lmi, lma] = a;
      auto [rdis, rmi, rma] = b;
      if (fabs(ldis - rdis) < EPS) {
        if (lmi == rmi) {
          return lma > rma;
        }
        return lmi > rmi;
      }
      return ldis > rdis;
    });

  unordered_map<int, int> con;
  unordered_map<int, unordered_map<int, double>> dis;
  for (int i = 0; i < n; ++i) {
    con[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      h.emplace(dis2(a[i], a[j]), min(i, j), max(i, j));
      dis[i][j] = dis2(a[i], a[j]) / 1.0;
    }
  }
  auto print_heap = [&](decltype(h) a) {
    while (!a.empty()) {
      auto [dis, mi, ma] = a.top();
      cout << dis << ' ' << mi << ' ' << ma << endl;
      a.pop();
    }
  };
  // print_heap(h);
  for (int qwq = 1; qwq <= n - 1; ++qwq) {
    auto [cdis, mi, ma] = h.top();
    h.pop();
    while (con.find(mi) == con.end() || con.find(ma) == con.end()) {
      tie(cdis, mi, ma) = h.top();
      h.pop();
    }
    int mic = con[mi];
    int mac = con[ma];
    con.erase(mi);
    con.erase(ma);
    for (auto [x, sz] : con) {
      dis[min(age, x)][max(age, x)] = (dis[min(mi, x)][max(mi, x)] * sz * mic
                                       + dis[min(ma, x)][max(ma, x)] * sz * mac)
                                      / (double)((mic + mac) * sz);
      h.emplace(dis[min(age, x)][max(age, x)], min(age, x), max(age, x));
    }
    con[age] = mic + mac;
    // cout << mi << ' ' << ma << endl;
    cout << con[age] << endl;
    // print_heap(h);
    ++age;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
