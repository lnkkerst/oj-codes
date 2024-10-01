#include <iostream>
using namespace std;

int n, m;
string s;

int main() {
  cin >> n >> m >> s;
  while (m--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x;
      char ch;
      cin >> x >> ch;
      s[x - 1] = ch;
    } else {
      int l, r, ans = 0;
      cin >> l >> r;
      for (int i = l - 1; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
          for (int k = j + 1; k < r; ++k) {
            ans += (s[i] == 'I' && s[j] == 'O' && s[k] == 'I');
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
