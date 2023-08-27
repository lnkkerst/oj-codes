#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s == "()") {
    cout << "NO" << endl;
    return;
  }
  string s1 = "(";
  string s2 = ")";
  for (int i = 1; i < s.length(); ++i) {
    s1.push_back(s1.back() == '(' ? ')' : '(');
    s2.push_back(s2.back() == '(' ? ')' : '(');
  }
  cout << "YES" << endl;
  if (s == s1 || s == s2) {
    for (int i = 1; i <= s.length(); ++i) {
      cout << '(';
    }
    for (int i = 1; i <= s.length(); ++i) {
      cout << ')';
    }
    cout << endl;
    return;
  } else {
    for (int i = 1; i <= s.length(); ++i) {
      cout << "()";
    }
    cout << endl;
    return;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
