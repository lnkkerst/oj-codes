#include <cstdio>

int main() {
  int x;
  while (233) {
    scanf("%d", &x);
    if (!x) {
      return 0;
    }
    printf("%s\n", x & 1 ? "Bob" : "Alice");
  }
}
