#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  vector<string> a(n + 1);
  unordered_map<string, int> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    dp[i] = 1;
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; ++i) {
    b[a[i]] = i;
  }
  for (int k = 1; k <= n; ++k) {
    string t = a[k];
    for (int i = 0; i < (int)t.size(); ++i) {
      for (int j = 'a'; j < t[i]; ++j) {
        t[i] = j;
        if (b.find(t) != b.end()) {
          dp[k] = max(dp[k], dp[b[t]] + 1);
        }
        t = a[k];
      }
      t.erase(i, 1);
      if (b.find(t) != b.end()) {
        dp[k] = max(dp[k], dp[b[t]] + 1);
      }
      t = a[k];
      for (char j = 'a'; j <= 'z'; ++j) {
        t.insert(i, string(1, j));
        if (b.find(t) != b.end()) {
          dp[k] = max(dp[k], dp[b[t]] + 1);
        }
        t = a[k];
      }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
      t = i + t;
      if (b.find(t) != b.end()) {
        dp[k] = max(dp[k], dp[b[t]] + 1);
      }
      t = a[k];
    }
    t = a[k];
  }
  cout << *max_element(dp.begin(), dp.end());
  return 0;
}
