#include <iostream>
#define int long long
using namespace std;

int n, a[200010];

int pd(int x) {
  int now = 1;
  while (x - now >= 0) {
    x -= now;
    now += 2;
  }
  if (x) {
    return -1;
  }
  return now >> 1;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i += 2) {
    cin >> a[i];
  }
  int last = 0;
  bool fl = 0;
  for (int i = 1; i <= n; i += 2) {
    int now = last + 1;
    while (1) {
      int t = pd(now * now + a[i + 1]);
      if (t != -1) {
        a[i] = now * now - last * last;
        last = t;
        break;
      }
      if (now * 2 - 1 > a[i + 1]) {
        fl = 1;
        break;
      }
      ++now;
    }
    if (fl) {
      break;
    }
  }
  if (fl) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  return 0;
}
