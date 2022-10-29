#include <cstdio>

using namespace std;

int n, l, g;

void cut(int &w, int &h) {
  while (w > g || h > g)
    w >>= 1, h >>= 1;
}

int main() {
  scanf("%d%d%d", &n, &l, &g);

  for (int i = 1; i <= n; i++) {
    bool f1 = 0, f2 = 0, f3 = 0;
    int w, h;
    scanf("%d%d", &w, &h);
    cut(w, h);
    if (w < l || h < l) {
      printf("Too Young\n");
      continue;
    }
    if (w != h) {
      printf("Too Simple\n");
      continue;
    }
    printf("Sometimes Naive\n");
  }
  return 0;
}