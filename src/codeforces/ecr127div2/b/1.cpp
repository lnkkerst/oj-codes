#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int last;
  cin >> last;
  vector<int> a;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x - last);
    last = x;
  }
  int cnt2 = 0, cnt3 = 0;
  for (auto i : a) {
    cnt2 += i == 2;
    cnt3 += i == 3;
    if (i >= 4) {
      cout << "NO" << endl;
      return;
    }
  }
  if (cnt2 && cnt3) {
    cout << "NO" << endl;
    return;
  }
  if (cnt2 >= 3) {
    cout << "NO" << endl;
    return;
  }
  if (cnt3 >= 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
