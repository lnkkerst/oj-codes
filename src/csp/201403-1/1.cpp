#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<int> b;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (b.find(-x) != b.end()) {
      ++ans;
    } else {
      b.insert(x);
    }
  }
  cout << ans << endl;
  return 0;
}
