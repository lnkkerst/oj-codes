#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a.emplace_back(x);
  }
  deque<int> que;
  puts("0");
  for (int i = 0; i < n - 1; ++i) {
    while (!que.empty() && a[que.back()] >= a[i]) {
      que.pop_back();
    }
    que.emplace_back(i);
    if (que.front() <= i - m) {
      que.pop_front();
    }
    printf("%d\n", a[que.front()]);
  }
  return 0;
}
