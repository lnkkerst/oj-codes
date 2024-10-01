#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans[2333] = {0};
  for (int i = 0; i < (int)s.length() - 1; ++i) {
    ans[i] = s[i] != s[i + 1];
  }
  ans[(int)s.length() - 1] = s[(int)s.length() - 1] == 'a';
  for (int i = 0; i < (int)s.length(); ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
