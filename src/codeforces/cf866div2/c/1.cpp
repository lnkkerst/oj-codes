#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++b[a[i]];
  }
  if (b.find(0) == b.end()) {
    cout << "Yes" << endl;
    return;
  }
  for (auto it = b.begin(); it != b.end(); ++it) {
    auto itl = it;
    ++it;
    if (it == b.end()) {
      if (b.size() == n) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
      return;
    }
    if (it->first - itl->first >= 3) {
      cout << "Yes" << endl;
      return;
    }
    if (it->first == itl->first + 1) {
      --it;
      continue;
    }
    int l = -1, r = 0;
    int ta = it->first;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == ta) {
        if (l == -1) {
          l = i;
        }

        r = i;
      }
    }
    for (int i = l; i <= r; ++i) {
      if (a[i] < ta) {
        --b[a[i]];
        if (b[a[i]] == 0) {
          cout << "No" << endl;
          return;
        }
      }
    }
    cout << "Yes" << endl;
    return;
    --it;
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
