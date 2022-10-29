#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, ans;
int a[1233], b[1233];

void merge_sort(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  merge_sort(l, mid), merge_sort(mid + 1, r);
  int i = l, j = mid + 1, pos = l;
  while (i <= mid && j <= r) {
    if (a[i] > a[j])
      ans += mid - i + 1, b[pos++] = a[j], ++j;
    else
      b[pos++] = a[i], ++i;
  }
  while (i <= mid)
    b[pos++] = a[i], ++i;
  while (j <= r)
    b[pos++] = a[j], ++j;
  for (int i = l; i <= r; ++i)
    a[i] = b[i];
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    memset(b, 0, sizeof(b));
    ans = 0;
    merge_sort(1, n);
    cout << ans << endl;
  }
  return 0;
}