#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  unordered_map<int, int> a;
  unordered_map<int, bool> b;
  for (int i = 1; i <= n; ++i) {
    string opt;
    int x;
    cin >> opt >> x;
    if (opt == "add") {
      ++a[x];
      cout << a[x] << endl;
      b[x] = 1;
    } else if (opt == "ask") {
      cout << b[x] << ' ' << a[x] << endl;
    } else {
      cout << a[x] << endl;
      a[x] = 0;
    }
  }
  return 0;
}