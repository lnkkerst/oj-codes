#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end(), [](const string &a, const string &b) -> bool {
    int pos = 0;
    while (pos < (int)a.size() && pos < (int)b.size()) {
      if (a[pos] > b[pos]) {
        return 1;
      }
      if (a[pos] < b[pos]) {
        return 0;
      }
      ++pos;
    }
    if (a.size() == b.size()) {
      return 0;
    }
    if (pos == (int)a.size()) {
      return 1;
    }
    return 0;
  });
  string ans;
  for (const auto &i : a) {
    ans.append(i);
  }
  cout << ans;
  return 0;
}
