#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define int long long

struct Node {
  string op;
  int p;
  int s;
};

auto solve() {
  vector<Node> a;
  Node in;

  while (cin >> in.op) {
    if (in.op == "cancel") {
      int id;
      cin >> id;
      in = a[id - 1];
      in.s = -in.s;
      a.emplace_back(in);
      continue;
    }
    double p;
    cin >> p >> in.s;
    in.p = (long long)(p * 100);
    a.emplace_back(in);
  }

  unordered_map<int, int> sIn, sOut;

  for (auto i : a) {
    if (i.op == "buy") {
      sIn[i.p] += i.s;
    } else {
      sOut[i.p] += i.s;
    }

    for (auto j : {&sIn, &sOut}) {
      if ((*j)[i.p] == 0) {
        j->erase(i.p);
      }
    }
  }

  int ans1, ans2 = 0;

  for (auto &i : {sIn, sOut}) {
    for (auto j : i) {
      for (auto money : {j.first, j.first - 1, j.first + 1}) {
        int cnt1 = 0, cnt2 = 0;
        for (auto k : sIn) {
          if (k.first >= money) {
            cnt1 += k.second;
          }
        }
        for (auto k : sOut) {
          if (k.first <= money) {
            cnt2 += k.second;
          }
        }

        int amount = min(cnt1, cnt2);
        if (ans2 < amount) {
          ans2 = amount;
          ans1 = money;
        }
        if (ans2 == amount && ans1 < money) {
          ans1 = money;
        }
      }
    }
  }
  cout << fixed << setprecision(2) << ans1 / 100.0 << ' ' << ans2 << endl;
}

auto main() -> signed {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
