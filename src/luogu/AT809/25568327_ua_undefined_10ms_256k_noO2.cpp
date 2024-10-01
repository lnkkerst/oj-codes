#include <bits/stdc++.h>
using namespace std;

int n, mw, ans;
int a[33], w[33];
int _n[33];
bool b[33];

void dfs(int step, int num) {
  if (step == num + 1) {
    int cnt = 0;
    for (int i = 1; i <= num; ++i) {
      cnt += w[a[i]];
    }
    bool f = 0;
    for (int i = 2; i <= num; ++i) {
      if (a[i] < a[i - 1]) {
        f = 1;
      }
    }
    if (cnt == mw && !f) {
      ++ans;
    }
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      b[i] = true;
      a[step] = i;
      dfs(step + 1, num);
      b[i] = false;
    }
  }
}

int main() {
  cin >> n >> mw;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; ++i) {
    dfs(1, i);
  }
  cout << ans << endl;
  return 0;
}
