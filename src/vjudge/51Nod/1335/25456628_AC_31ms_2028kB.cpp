#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end(), less<char>())) {
      cout << "0 0\n";
      continue;
    }
    int tmn = s.back(), pos = s.length() - 1;
    for (int i = (int)s.length() - 1; i >= 0; --i) {
      if (s[i] > tmn)
        pos = i;
      tmn = min(tmn, (int)s[i]);
    }
    // cout << pos << endl;
    string smin = s;
    int ansx = 0, ansy = 0;
    for (int i = pos + 1; i < (int)s.length(); ++i) {
      auto t = s;
      reverse(t.begin() + pos, t.begin() + i + 1);
      if (smin > t) {
        smin = t;
        ansx = pos;
        ansy = i;
      }
    }
    cout << ansx << ' ' << ansy << endl;
  }
  return 0;
}