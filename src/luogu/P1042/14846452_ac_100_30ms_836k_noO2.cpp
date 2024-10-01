#include <cstdio>
#define MAXN 6000

int main() {
  char a;
  int score[MAXN][4], sum = 0, top11 = 0, top21 = 0;
  while (1) {
    sum++;

    scanf("%c", &a);

    if (a == 'E') {
      break;
    } else if (a == 'W') {
      score[top11][0]++;
      score[top21][2]++;
    } else if (a == 'L') {
      score[top11][1]++;
      score[top21][3]++;
    }

    if ((score[top11][0] >= 11 && score[top11][0] - score[top11][1] >= 2)
        || (score[top11][1] >= 11 && score[top11][1] - score[top11][0] >= 2)) {
      top11++;
    }

    if ((score[top21][2] >= 21 && score[top21][2] - score[top21][3] >= 2)
        || (score[top21][3] >= 21 && score[top21][3] - score[top21][2] >= 2)) {
      top21++;
    }
  }

  for (int i = 0; i <= top11; i++) {
    printf("%d:%d\n", score[i][0], score[i][1]);
  }

  putchar('\n');

  for (int i = 0; i <= top21; i++) {
    printf("%d:%d\n", score[i][2], score[i][3]);
  }

  return 0;
}
