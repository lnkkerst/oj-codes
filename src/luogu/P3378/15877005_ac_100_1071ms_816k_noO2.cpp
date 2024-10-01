#include <cstdio>
#include <queue>
#include <vector>
std::priority_queue<int, std::vector<int>, std::greater<int>> q;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d", &x);
      q.push(x);
    } else if (x == 2) {
      printf("%d\n", q.top());
    } else {
      q.pop();
    }
  }
  return 0;
}
