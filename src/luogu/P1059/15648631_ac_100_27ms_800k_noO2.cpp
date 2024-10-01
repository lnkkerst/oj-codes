#include <cstdio>
#include <set>

std::set<int> a;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    a.insert(t);
  }

  printf("%d\n", a.size());

  while (a.size() != 0) {
    printf("%d ", *a.begin());
    a.erase(*a.begin());
  }
}
