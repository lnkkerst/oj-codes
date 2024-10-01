#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  int ans = 0;
  vector<int> aa;
  do {
    set<int> b;
    for (int i = 0; i < n; ++i) {
      b.insert(gcd(a[i], a[(i + 1) % n]));
      // cout << a[i] << ' ' << a[(i + 1) % n] << ' ' << gcd(a[i], a[(i + 1) %
      // n])
      //      << endl;
    }
    if (b.size() >= ans) {
      ans = b.size();
      aa = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << endl;
  for (auto i : aa) {
    cout << i << ' ';
  }
  cout << endl;
}
