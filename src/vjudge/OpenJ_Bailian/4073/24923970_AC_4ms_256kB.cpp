#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) {
      return 0;
    }
    vector<string> a;
    int minl = 1e9;
    for (int i = 1; i <= n; ++i) {
      string inp;
      cin >> inp;
      minl = min(minl, (int)inp.length());
      reverse(inp.begin(), inp.end());
      a.push_back(inp);
    }
    string ans;
    for (int i = 0; i < minl; ++i) {
      bool fl = 1;
      for (int j = 1; j < (int)a.size(); ++j) {
        if (a[j][i] != a[0][i]) {
          fl = 0;
          break;
        }
      }
      if (fl) {
        ans += a[0][i];
      } else {
        break;
      }
    }
    if (!ans.length()) {
      cout << endl;
    } else {
      reverse(ans.begin(), ans.end());
      cout << ans << endl;
    }
  }
  return 0;
}
