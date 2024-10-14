#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int a, b, n;
  cin >> a >> b >> n;
  auto calc = [&](int a, int b) {
    int ga = a - n % a - 1;
    int gb = b - n % b - 1;

    int gg = ga + gb;
    vector<int> c(n * 3 + 10);
    int na = a, nb = b;
    // cout << ga << ' ' << gb << endl;

    for (int i = min(na, nb); i <= n; i = min(na, nb)) {
      if (na == i && nb != i) {
        c[i] = 1;
        na += a;
        continue;
      }
      if (na != i && nb == i) {
        c[i] = 1;
        nb += b;
        continue;
      }
      if (na == i && nb == i) {
        c[i] = 1;
        if (ga) {
          ga--;
          c[i - 1] = 1;
          na--;
          na += a;
          nb += b;
        } else {
          if (gb) {
            gb--;
            c[i - 1] = 1;
            nb--;
            nb += b;
            na += a;
          } else {
            ga += a - 1;
            ga--;
            c[i - 1] = 1;
            na--;
            na += a;
            nb += b;
          }
        }
      }
    }

    // for (int i = 1; i <= n; ++i) {
    //   if (i % a == 0) {
    //     c[i] = 1;
    //   }
    // }
    // int last = 0;
    // for (int i = 1; i <= n; i++) {
    //   if (i - last >= b) {
    //     if (c[i] == 1) {
    //       if (ga == 0) {
    //         c[i - 1] = 1;
    //         last = i - 1;
    //       } else {
    //         ++i;
    //         ++n;
    //         ++c[i];
    //         last = i;
    //         --ga;
    //       }
    //     } else {
    //       c[i] = 1;
    //       last = i;
    //     }
    //   }
    // }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += c.at(i);
      // cout << c[i] << ' ';
      // if (i % 10 == 0) {
      //   cout << endl;
      // }
    }
    // cout << endl;
    return ans;
  };
  int ans = min(calc(a, b), calc(b, a));
  cout << ans << endl;
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