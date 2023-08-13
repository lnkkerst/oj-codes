#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a;
  int cur = 0;
  char last = s[0];
  for (auto i : s) {
    if (i == last) {
      ++cur;
    } else {
      last = i;
      a.emplace_back(cur);
      cur = 1;
    }
  }
  a.emplace_back(cur);
  cout << *max_element(a.begin(), a.end()) + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
