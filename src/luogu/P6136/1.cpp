#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define int long long

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
  a;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.insert((x << 31) + i);
  }
  int ansa = 0;
  for (int i = 1; i <= m; ++i) {
    int opt, x;
    cin >> opt >> x;
    x ^= last;
    if (opt == 1) {
      a.insert((x << 31) + n + i);
    } else if (opt == 2) {
      a.erase(a.lower_bound(x << 31));
    } else if (opt == 3) {
      int ans = a.order_of_key(x << 31) + 1;
      ansa ^= ans;
      last = ans;
    } else if (opt == 4) {
      int ans;
      if (x >= a.size()) {
        ans = *a.rbegin();
      } else {
        ans = *a.find_by_order(x - 1);
      }
      ans >>= 31;
      ansa ^= ans;
      last = ans;
    } else if (opt == 5) {
      int ans = *(--a.lower_bound(x << 31)) >> 31;
      ansa ^= ans;
      last = ans;
    } else if (opt == 6) {
      int ans = *a.lower_bound((x << 31) + n + m) >> 31;
      ansa ^= ans;
      last = ans;
    }
  }
  cout << ansa << endl;
  return 0;
}
