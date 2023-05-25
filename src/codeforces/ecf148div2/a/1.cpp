#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  for (int i = 1; i < s.size() / 2; ++i) {
    if (s[i] != s[i - 1]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
