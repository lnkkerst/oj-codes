#pragma GCC optimize(2)
#include <algorithm>
#include <bits/extc++.h>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace __gnu_cxx;
using namespace std;

constexpr int MAXN = 100010;

void solve() {
  int n;
  cin >> n;
  vector<rope<int> *> a(n + 10);
  int cur = 1;
  a[cur] = new rope<int>();
  while (n--) {
    char c;
    cin >> c;
    if (c == '+') {
      int x;
      cin >> x;
      ++cur;
      a[cur] = (new rope<int>(*a[cur - 1]));
      a[cur]->push_back(x);
    }
    if (c == '-') {
      int k;
      cin >> k;
      ++cur;
      a[cur] = (new rope<int>(*a[cur - 1]));
      for (int i = 1; i <= k; ++i) {
        a[cur]->pop_back();
      }
    }
    if (c == '!') {
      delete a[cur];
      --cur;
    }
    if (c == '?') {
      cout << (set<int>{a[cur]->begin(), a[cur]->end()}).size() << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
