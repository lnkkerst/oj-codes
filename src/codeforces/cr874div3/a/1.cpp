#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<string, int> b;
  for (int i = 1; i < s.size(); ++i) {
    string t;
    t += s[i - 1];
    t += s[i];
    b[t]++;
  }
  cout << b.size() << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
