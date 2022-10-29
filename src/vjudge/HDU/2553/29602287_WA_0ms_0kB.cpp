#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
int n, ans;
vector<bool> y, dx, dy;

void dfs(int step) {
  if (step > n) {
    ++ans;
  }
  for (int i = 1; i <= n; i++) {
    if (!y[i] && !dx[i + step] && !dy[step - i + n]) {
      x[step] = i;
      y[i] = 1;
      dx[i + step] = 1;
      dy[step - i + n] = 1;
      dfs(step + 1);
      y[i] = 0;
      dx[i + step] = 0;
      dy[step - i + n] = 0;
    }
  }
}

int main() {
  while (true) {
    cin >> n;
    if (!n)
      break;
    x = vector<int>(n + 1, 0);
    y = dx = dy = vector<bool>(n + 1, 0);
    ans = 0;
    dfs(1);
    cout << ans << endl;
  }
  return 0;
}