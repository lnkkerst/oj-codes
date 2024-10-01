//
// Created by icpc-sandbox on 2022/10/3.
//
#include <bits/stdc++.h>
using namespace std;
// const int N=1e5+5;
int n, k, q;
map<int, int> mp;
int query(int pos) {
  if (mp.count(pos)) {
    return mp[pos];
  }
  if (pos == 0 || pos == n + 1) {
    return 1;
  }
  return pos <= k ? 1 : 0;
}
int main() {
  //    freopen("ts.in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T, x, y;
  cin >> T;
  for (int Tim = 1; Tim <= T; ++Tim) {
    cout << "Case " << Tim << ":\n";
    mp.clear();
    cin >> n >> k >> q;
    int ans = 1;
    while (q--) {
      cin >> x >> y;
      int cx = query(x - 1) + query(x + 1);
      if (cx == 0) {
        --ans;
      } else if (cx == 2) {
        ++ans;
      }
      mp[x] = 0;
      int cy = query(y - 1) + query(y + 1);
      if (cy == 0) {
        ++ans;
      } else if (cy == 2) {
        --ans;
      }
      mp[y] = 1;
      cout << ans << '\n';
    }
  }
  return 0;
}
