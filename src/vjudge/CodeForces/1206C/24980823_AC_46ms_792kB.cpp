#include <iostream>
using namespace std;

int n, a[200010];

int main() {
  cin >> n;
  int now = 1;
  if (!(n & 1)) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n * 2; i += 2) {
    a[now] = i;
    if (now <= n) {
      a[now + n] = i + 1;
      now = now + n + 1;
    } else {
      a[now - n] = i + 1;
      now = now - n + 1;
    }
  }
  puts("YES");
  for (int i = 1; i <= n * 2; ++i)
    cout << a[i] << ' ';
  return 0;
}