#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  unordered_map<string, int> ans;
  for (auto &i : a) {
    cin >> i, ans[i] = 1;
  }
  for (const auto &wd : a) {
    auto t = wd;
    for (auto &i : t) {
      char tmp = i;
      for (char j = 'a'; j < i; ++j) {
        i = j;
        ans[wd] = max(ans[wd], ans[t] + 1);
        i = tmp;
      }
    }
    for (decltype(t.size()) i = 0; i < t.size(); ++i) {
      t.erase(i, 1);
      if (ans.find(t) != ans.end() && t < wd) {
        ans[wd] = max(ans[wd], ans[t] + 1);
      }
      t = wd;
    }
    for (decltype(t.size()) i = 0; i <= t.size(); ++i) {
      for (char j = 'a'; j <= 'z'; ++j) {
        t.insert(i, string{j});
        if (ans.find(t) != ans.end() && t < wd) {
          ans[wd] = max(ans[wd], ans[t] + 1);
        }
        t = wd;
      }
    }
  }
  int ma = 0;
  for (const auto &i : ans) {
    ma = max(ma, i.second);
  }
  cout << ma;
  return 0;
}
