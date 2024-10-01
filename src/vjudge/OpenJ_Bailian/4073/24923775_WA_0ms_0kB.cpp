#include <iostream>
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
      string res;
      for (string::reverse_iterator i = inp.rbegin(); i != inp.rend(); ++i) {
        res += *i;
      }
      minl = min(minl, (int)res.length());
      a.push_back(res);
    }
    string ans;
    for (int i = 0; i <= minl; ++i) {
      bool fl = 1;
      for (int j = 1; j < (int)a.size(); ++j) {
        if (a[j][i] != a[j - 1][i]) {
          fl = 0;
          break;
        }
      }
      if (fl) {
        ans += a[0][i];
      }
    }
    for (int i = (int)ans.length() - 1; i >= 1; --i) {
      cout << ans[i];
    }
    cout << ans[0] << endl;
  }
  return 0;
}
