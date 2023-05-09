#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, unordered_map<int, pair<int, int>>> b;

void solve() {
  int n, k;
  cin >> n >> k;
  auto ik = b.find(k);
  if (ik == b.end()) {
    cout << "NO" << endl;
    return;
  }
  auto in = ik->second.find(n);
  if (in == ik->second.end()) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= in->second.first; ++i) {
    cout << "1 ";
  }
  for (int i = 1; i <= in->second.first; ++i) {
    cout << "-1 ";
  }
  cout << endl;
}

void init() {
  int op = 0;
  for (int i = 0; i <= 100; ++i) {
    op += max(0, i - 1);
    int ne = 0;
    for (int j = 0; j <= 100; ++j) {
      ne += max(0, j - 1);
      b[op + ne][i + j] = make_pair(op, ne);
    }
  }
}

int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
