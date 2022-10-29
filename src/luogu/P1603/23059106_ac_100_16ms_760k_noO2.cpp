#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string s[27] = {"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "night",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                "twenty",  "a",       "both",      "another",  "first",
                "second",  "third"};
int mul[27] = {0,  1,  4,  9,  16, 25, 36, 49, 64, 81, 0, 21, 44, 69,
               96, 25, 56, 89, 24, 61, 0,  1,  4,  1,  1, 4,  9};
int a[7], top = 0;

int main() {
  for (int i = 1; i <= 6; ++i) {
    string st;
    cin >> st;
    for (int j = 1; j <= 26; j++)
      if (st == s[j])
        a[++top] = mul[j];
  }
  sort(a + 1, a + top + 1);
  bool f = 0;
  for (int i = 1; i <= top; ++i) {
    if (f)
      printf("%.2d", a[i]);
    else {
      cout << a[i];
      f = 1;
    }
  }
  if (!f)
    cout << "0";
  return 0;
}