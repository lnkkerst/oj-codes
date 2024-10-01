#include <iostream>
#include <queue>
#define int long long
using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
  a;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    a.push(make_pair(x, y));
  }
  int tot = 0;
  while (!a.empty()) {
    tot += a.top().second;
    if (tot >= k) {
      cout << a.top().first;
      return 0;
    }
    a.pop();
  }
  return 0;
}
