#include <cstdio>
#include <cstring>

int main() {
  int k, at = 0;
  char n[500], ans[500];
  bool b[500] = {0};

  scanf("%s%d", n, &k);

  int l = strlen(n);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < l - 1; j++) {
      int t = j + 1;

      while (b[t]) {
        t++;
      }

      if (n[j] > n[t] && !b[j]) {
        b[j] = 1;

        break;
      }
    }
  }

  int i = 0;

  while (l - k) {
    if (!b[i]) {
      ans[at++] = n[i];

      l--;
    }

    i++;
  }

  for (i = 0; ans[i] == '0'; i++)
    ;

  if (i == at) {
    printf("0");
  } else {
    for (i = 0; i < at; i++) {
      printf("%c", ans[i]);
    }
  }

  return 0;
}
