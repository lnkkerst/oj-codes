#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#define int long long
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, splay_tree_tag,
     tree_order_statistics_node_update>
    a;

signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int opt, x;
    cin >> opt >> x;
    if (opt == 1)
      a.insert((x << 20) + i);
    else if (opt == 2)
      a.erase(a.lower_bound(x << 20));
    else if (opt == 3)
      cout << a.order_of_key(x << 20) + 1 << endl;
    else if (opt == 4)
      cout << (*a.find_by_order(x - 1) >> 20) << endl;
    else if (opt == 5)
      cout << (*(--a.lower_bound(x << 20)) >> 20) << endl;
    else if (opt == 6)
      cout << (*a.lower_bound((x << 20) + n) >> 20) << endl;
  }
  return 0;
}