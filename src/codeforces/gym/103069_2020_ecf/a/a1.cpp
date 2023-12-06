#pragma GCC optimize(2)
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
char c[1100000];
// #define int long long
int numOfC[1000010][70], numOfCD[1000010][4000], numOfDCD[1000010][4000],
    numOfCDCD[1000010][4000];

void solve() {
  cin >> c;
  int l = strlen(c);
  for (int i = 0; i < l; ++i) {
    if (c[i] >= 'a' && c[i] <= 'z') {
      c[i] = c[i] - 'a' + 10;
    } else if (c[i] >= '0' && c[i] <= '9') {
      c[i] -= '0';
    } else {
      c[i] = 10 + 26 + c[i] - 'A';
    }
  }
}
signed main() {
  cout << 62 * 62;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
