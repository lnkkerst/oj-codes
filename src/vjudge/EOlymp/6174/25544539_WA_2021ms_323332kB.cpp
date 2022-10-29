#include <iostream>
#define int long long
using namespace std;

bool fl;

void dfs(int a, int b, int s) {
  if (fl)
    return;
  if (a == s || b == s) {
    fl = 1;
    return;
  }
  if (a + b < s && b < s)
    dfs(a + b, b, s);
  if (a < s && a + b < s)
    dfs(a, a + b, s);
}

signed main() {
  int a, b, s;
  cin >> a >> b >> s;
  dfs(a, b, s);
  puts(fl ? "YES" : "NO");
  return 0;
}