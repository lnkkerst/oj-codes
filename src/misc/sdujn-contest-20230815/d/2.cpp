#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int cntl = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++cnt;
      ++cntl;
    } else {
      --cnt;
    }
    if (cnt == 0) {
      cntl = 0;
    }
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
