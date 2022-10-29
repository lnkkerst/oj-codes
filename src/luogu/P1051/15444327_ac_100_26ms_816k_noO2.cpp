#include <iostream>

int main() {
  int n, a1, a2, a3, sum = 0, max = -1;
  char s1, s2;
  std::string st, s;

  std::cin >> n;

  while (n--) {
    int t = 0;

    std::cin >> st >> a1 >> a2 >> s1 >> s2 >> a3;

    if (a1 > 80 && a3 >= 1)
      t += 8000;

    if (a1 > 85 && a2 > 80)
      t += 4000;

    if (a1 > 90)
      t += 2000;

    if (a1 > 85 && s2 == 'Y')
      t += 1000;

    if (a2 > 80 && s1 == 'Y')
      t += 850;

    if (t > max) {
      max = t;

      s = st;
    }

    sum += t;
  }

  std::cout << s << std::endl << max << std::endl << sum;

  return 0;
}