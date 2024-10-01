#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), dp(n + 1, 0x7fffffff);
  unordered_map<int, int> id;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], id[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  int ans = 0;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = ans;
    if (id[b[i]] > dp[ans]) {
      dp[++ans] = id[b[i]];
    } else {
      while (l < r) {
        int mid = (l + r) >> 1;
        if (dp[mid] > id[b[i]]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      dp[l] = min(id[b[i]], dp[l]);
    }
  }
  cout << ans;
  return 0;
}
