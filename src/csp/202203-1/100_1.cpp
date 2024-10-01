#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  unordered_map<int, bool> b;
  b[0] = true;
  for (int i = 1; i <= k; ++i) {
    int x, y;
    cin >> x >> y;
    if (!b[y]) {
      ++ans;
    }
    b[x] = true;
  }
  cout << ans;
  return 0;
}
