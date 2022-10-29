#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
set<int> aa;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    aa.insert(x);
  }
  vector<int> a{aa.begin(), aa.end()};
  int ans = -1;
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = a[i] << 1; j <= a.back() << 1; j += a[i])
      ans = max(ans, *(lower_bound(a.begin(), a.end(), j) - 1) % a[i]);
  }
  cout << ans;
  return 0;
}