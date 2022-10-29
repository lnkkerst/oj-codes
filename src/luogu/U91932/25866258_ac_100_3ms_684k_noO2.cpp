#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000

int a[MAXN], b[MAXN], c[MAXN];

int main() {
  int x = 0, lena, lenb, lenc;
  std::string a1, b1;
  std::cin >> a1 >> b1;
  lena = a1.length();
  lenb = b1.length();
  if (lena > lenb)
    lenc = lena;
  else
    lenc = lenb;
  for (int i = 0; i < lena; i++)
    a[i] = a1[lena - i - 1] - '0';
  for (int i = 0; i < lenb; i++)
    b[i] = b1[lenb - i - 1] - '0';
  for (int i = 0; i < lenc; i++) {
    c[i] = (a[i] + b[i] + x) % 10;
    x = (a[i] + b[i] + x) / 10;
  }
  if (x > 0)
    c[lenc] = x;
  if (c[lenc] == 0)
    lenc--;
  for (int i = lenc; i >= 0; i--)
    std::cout << c[i];
  return 0;
}