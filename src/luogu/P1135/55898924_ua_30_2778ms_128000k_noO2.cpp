#include <iostream>
using namespace std;

int n, a, b, ans = 1e9;
int k[210];
bool vis[210];

void dfs(int step, int now) {
  if (step >= ans) {
    return;
  }
  if (vis[now]) {
    return;
  }
  if (now < 1 || now > n) {
    return;
  }
  if (now == b) {
    ans = min(ans, step);
    return;
  }
  dfs(step + 1, now + k[now]);
  dfs(step + 1, now - k[now]);
}

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> k[i];
  }
  dfs(0, a);
  cout << ans;
  return 0;
}