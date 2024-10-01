#include <iostream>
#define int long long
using namespace std;

int a[26];
string str;

int jc(int x) {
  return x == 1 || x == 0 ? 1 : x * jc(x - 1);
}

signed main() {
  cin >> str;
  for (auto i : str) {
    ++a[i - 'a'];
  }
  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (a[i] & 1) {
      --a[i], ++cnt;
    }
  }
  if (cnt >= 2) {
    cout << 0;
    return 0;
  }
  int ans = jc((int)str.length() >> 1);
  for (int i = 0; i < 26; ++i) {
    ans /= jc(a[i] >> 1);
  }
  cout << ans << endl;
  return 0;
}
