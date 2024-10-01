#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_set<int> b;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if (b.find(x) == b.end()) {
        cout << x << ' ';
        b.insert(x);
      }
    }
    cout << endl;
  }
  return 0;
}
