#include <cstdio>
#include <cstring>

int main() {
  int k;
  char n[500];
  bool b[500] = {0};

  scanf("%s%d", n, &k);

  int l = strlen(n);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < l - 1; j++) {
      int t = j + 1;

      while (b[t])
        t++;

      if (n[j] > n[t] && !b[j]) {
        b[j] = 1;

        break;
      }
    }
  }

  int i = 0;

  while (l - k) {
    if (!b[i]) {
      printf("%c", n[i]);

      l--;
    }

    i++;
  }

  return 0;
}
