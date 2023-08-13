#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  unordered_map<char, deque<int>> b;
  for (int i = 0; i < s.length(); ++i) {
    b[s[i]].emplace_back(i + 1);
  }
  int tot = 0;
  int ans = 1e9;
  for (auto &i : b) {
    i.second.emplace_front(0);
    i.second.emplace_back(s.length() + 1);
    int tmp = 0;
    for (int j = 1; j < i.second.size(); ++j) {
      int tar = i.second[j] - i.second[j - 1] - 1;
      int t1 = 0;
      while (tar) {
        ++t1;
        if (tar == 1) {
          break;
        }
        tar -= (tar + 1) / 2;
      }
      tmp = max(tmp, t1);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
