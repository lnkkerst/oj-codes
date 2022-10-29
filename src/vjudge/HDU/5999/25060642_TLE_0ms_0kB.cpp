#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (i % 3 == 2)
        continue;
      ans += a[i];
    }
    printf("Case #%d: %d\n", k, ans);
  }
  return 0;
}