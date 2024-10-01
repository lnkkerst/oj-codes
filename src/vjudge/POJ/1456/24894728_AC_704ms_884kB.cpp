#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int v, d;
  bool operator<(const Node b) const {
    return this->d < b.d;
  }
} a[200010];

int n;

int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].v >> a[i].d;
    }
    sort(a + 1, a + n + 1);
    priority_queue<int, vector<int>, greater<int>> q;
    int now = 1;
    for (int i = 1; i <= n; ++i) {
      if (now <= a[i].d) {
        q.push(a[i].v);
        ++now;
      } else if (a[i].v > q.top()) {
        q.pop();
        q.push(a[i].v);
      }
    }
    int ans = 0;
    while (!q.empty()) {
      ans += q.top();
      q.pop();
    }
    cout << ans << endl;
  }
  return 0;
}
