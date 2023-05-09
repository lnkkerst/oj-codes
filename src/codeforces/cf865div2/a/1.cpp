#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1 || b == 1) {
    cout << 1 << endl;
    cout << a << ' ' << b << endl;
    return;
  }
  cout << 2 << endl;
  cout << a - 1 << ' ' << 1 << endl;
  cout << a << ' ' << b << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
