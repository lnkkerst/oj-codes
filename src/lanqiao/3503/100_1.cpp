#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int l = 0; l < s.size(); ++l) {
    for (int r = l + 1; r < s.size(); ++r) {
      int i = l, j = r;
      while (i < j && s[i] == s[j]) {
        ++i;
        --j;
      }
      if (i > j) {
        continue;
      }
      ans += s[i] > s[j];
    }
  }
  cout << ans << endl;
  return 0;
}
