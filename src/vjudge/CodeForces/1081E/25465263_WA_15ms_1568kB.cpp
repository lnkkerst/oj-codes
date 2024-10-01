#include <iostream>
#define int long long
using namespace std;

int n, a[200010];

int pd(int x) {
  int num = 1;
  while (x - num >= 0) {
    x -= num;
    num += 2;
  }
  if (x) {
    return -1;
  }
  return num >> 1;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i += 2) {
    cin >> a[i];
  }
  int now = 0;
  bool fl = 0;
  for (int i = 1; i <= n; i += 2) {
    int num = now + 1;
    while (1) {
      int t = pd(num * num + a[i + 1]);
      if (t != -1) {
        a[i] = num * num - now * now;
        now = t;
        break;
      }
      if (num * 2 - 1 > a[i + 1]) {
        fl = 1;
        break;
      }
      ++num;
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
