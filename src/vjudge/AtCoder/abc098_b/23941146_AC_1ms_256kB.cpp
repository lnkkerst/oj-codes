#include <iostream>
using namespace std;

int n, ans = -1;
char a[233];
bool cntl[26], cntr[26];

int solve(int pos) {
  int ret = 0;
  for (int i = 0; i < 26; ++i) {
    cntl[i] = cntr[i] = 0;
  }
  for (int i = 1; i <= pos; ++i) {
    cntl[a[i] - 'a'] = 1;
  }
  for (int i = pos + 1; i <= n; ++i) {
    cntr[a[i] - 'a'] = 1;
  }
  for (int i = 0; i < 26; ++i) {
    if (cntl[i] && cntr[i]) {
      ++ret;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;
  return 0;
}
