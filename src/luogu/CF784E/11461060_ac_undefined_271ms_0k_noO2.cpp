#include <cstdio>

int main() {
  bool iIn1, iIn2, iIn3, iIn4;
  scanf("%d%d%d%d", &iIn1, &iIn2, &iIn3, &iIn4);
  printf("%d",
         ((iIn1 ^ iIn2) & (iIn3 | iIn4)) ^ ((iIn2 & iIn3) | (iIn1 ^ iIn4)));
  return 0;
}