#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<set<string>> a(512);
  for (int i = 1; i <= n; ++i) {
    string team, prob, status;
    cin >> team >> prob >> status;
    if (status == "accepted") {
      a[prob[0]].insert(team);
    }
  }
  int ma = 0;
  for (int i = 'A'; i <= 'Z'; ++i) {
    ma = max(ma, (int)a[i].size());
  }
  int ans = 'A';
  for (; ans <= 'Z'; ++ans) {
    if (a[ans].size() == ma) {
      break;
    }
  }
  cout << (char)ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
