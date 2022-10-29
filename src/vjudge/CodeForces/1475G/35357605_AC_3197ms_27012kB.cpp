#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> fac(200011);
  for (int i = 1; i <= 200010; ++i) {
    for (int j = i * 2; j <= 200010; j += i) {
      fac[j].push_back(i);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    unordered_map<int, int> b;
    int ma = -1;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.emplace_back(x);
      ++b[x];
      ma = max(ma, x);
    }
    sort(a.begin(), a.end());
    vector<int> f(ma + 1);
    for (int i = 1; i <= ma; ++i) {
      if (b[i]) {
        for (auto j : fac[i]) {
          f[i] = max(f[i], f[j]);
        }
        f[i] += b[i];
      }
    }
    cout << n - *max_element(f.begin(), f.end()) << endl;
  }
}