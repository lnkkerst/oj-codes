#include <bits/stdc++.h>
using namespace std;

int ans, a[1000100];
int n;

bool cmp(int a, int b) {
  ++ans;
  return a == b;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    a[i] = i;
  stable_sort(a + 1, a + n + 1, cmp);
  printf("%d\n", ans);
}