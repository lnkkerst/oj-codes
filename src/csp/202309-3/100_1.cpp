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
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

constexpr int MOD = 1e9 + 7;

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = (res * x) % MOD;
    }
    x = (x * x) % MOD;
    k >>= 1;
  }
  return res;
}

struct Node {
  int pre;
  int sup;
  Node operator+(const Node &b) const {
    return {(pre + b.pre) % MOD, sup};
  }
  Node operator-(const Node &b) const {
    return {(pre - b.pre + MOD) % MOD, sup};
  }
  Node operator*(const Node &b) const {
    return {(pre * b.pre) % MOD, sup + b.sup};
  }
  Node operator-() const {
    return {(-pre + MOD) % MOD, sup};
  }
  bool com(const Node &b) const {
    return sup == b.sup;
  }
  int calc(int x) {
    return pre * qmi(x, sup) % MOD;
  }
};

struct Nodes {
  vector<Node> data;
  Node &operator[](int index) {
    return data[index];
  }
  Nodes operator+(const Nodes &b) const {
    auto res = data;
    for (auto &i : b.data) {
      res.emplace_back(i);
    }
    return {res};
  }
  Nodes operator-(const Nodes &b) const {
    auto res = data;
    for (auto i : b.data) {
      i.pre = (i.pre * -1 + MOD) % MOD;
      res.emplace_back(i);
    }
    return {res};
  }
  Nodes operator*(const Nodes &b) const {
    decltype(data) res;
    for (int i = 0; i < data.size(); ++i) {
      for (int j = 0; j < b.data.size(); ++j) {
        res.emplace_back(data[i] * b.data[j]);
      }
    }
    return {res};
  }
  Nodes simplify() const {
    decltype(data) res;
    unordered_map<int, vector<Node>> b;
    for (auto i : data) {
      b[i.sup].emplace_back(i);
    }
    for (auto i : b) {
      auto v = i.second;
      auto tmp = v[0];
      for (int i = 1; i < v.size(); ++i) {
        tmp = tmp + v[i];
      }
      res.emplace_back(tmp);
    }
    return {res};
  }
  int calc(int x) const {
    int res = 0;
    for (auto i : data) {
      res += i.calc(x);
      res %= MOD;
    }
    return res;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin.get();
  getline(cin, s);
  stringstream ss(s);
  deque<string> b;
  while (ss >> s) {
    b.emplace_back(s);
  }
  while (m--) {
    int id;
    cin >> id;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    stack<Nodes> st;
    for (auto s : b) {
      if (s[0] == 'x') {
        int cid = stoi(s.substr(1));
        if (cid != id) {
          st.push({{{a[cid], 0}}});
        } else {
          st.push({{{1, 1}}});
        }
      } else if (s == "*" || s == "+" || s == "-") {
        auto t1 = st.top();
        st.pop();
        auto t2 = st.top();
        st.pop();
        if (s[0] == '*') {
          st.push((t1 * t2).simplify());
        } else if (s[0] == '+') {
          st.push((t1 + t2).simplify());
        } else {
          st.push((t2 - t1).simplify());
        }
      } else {
        st.push({{{stoi(s), 0}}});
      }
    }
    auto fx = st.top().simplify();
    for (auto &x : fx.data) {
      if (x.sup == 0) {
        x.pre = 0;
      } else {
        x = {x.sup * x.pre, (x.sup - 1 + MOD) % MOD};
      }
    }
    cout << (fx.calc(a[id]) % MOD + MOD) % MOD << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
