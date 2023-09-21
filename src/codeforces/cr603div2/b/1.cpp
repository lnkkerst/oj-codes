#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  map<string, int> b1, b2;
  for (auto &i : a) {
    cin >> i;
    ++b1[i];
  }
  int ans = 0;
  for (auto &i : a) {
    if (b2[i]) {
      ++ans;
      [&]() {
        for (int j = 0; j < 4; ++j) {
          for (int k = '0'; k <= '9'; ++k) {
            i[j] = k;
            if (!b1[i]) {
              return;
            }
          }
        }
      }();
    }
    b2[i] = true;
    b1[i]++;
  }
  cout << ans << endl;
  for (auto i : a) {
    cout << i << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
