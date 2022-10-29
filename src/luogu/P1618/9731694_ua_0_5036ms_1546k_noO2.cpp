/*
题目背景

本题为提交答案题，您可以写程序或手算在本机上算出答案后，直接提交答案文本，也可提交答案生成程序。

题目描述

将 1,2, \cdots ,91,2,?,9 共 99 个数分成 33 组，分别组成 33 个三位数，且使这 33
个三位数构成 1:2:31:2:3 的比例，试求出所有满足条件的 33 个三位数。

输入输出格式

输入格式：
木有输入

输出格式：
若干行，每行 33 个数字。按照每行第 11 个数字升序排列。

输入输出样例

输入样例#1： 复制
无
输出样例#1： 复制
192 384 576
* * *
...

* * *
（输出被和谐了）
*/
#include <cstdio>
using namespace std;
int main() {
  int x, y, z, t, u, v, w;
  scanf("%ld%ld%ld", &u, &v, &w);
  for (int a = 1; a <= 9; a++)
    for (int b = 1; b <= 9; b++)
      for (int c = 1; c <= 9; c++)
        for (int d = 1; d <= 9; d++)
          for (int e = 1; e <= 9; e++)
            for (int f = 1; f <= 9; f++)
              for (int g = 1; g <= 9; g++)
                for (int h = 1; h <= 9; h++)
                  for (int i = 1; i <= 9; i++) {
                    if ((a * 100 + b * 10 + c) * v * w ==
                            (d * 100 + e * 10 + f) * u * w &&
                        (a * 100 + b * 10 + c) * v * w ==
                            (g * 100 + h * 10 + i) * u * v &&
                        a != b && a != c && a != d && a != e && a != f &&
                        a != g && a != h && a != i && b != c && b != d &&
                        b != e && b != f && b != g && b != h && b != i &&
                        c != d && c != e && c != f && c != g && c != h &&
                        c != i && d != e && d != f && d != g && d != h &&
                        d != i && e != f && e != g && e != h && e != i &&
                        f != g && f != h && f != i && g != h && g != i &&
                        h != i) {
                      x = (a * 100 + b * 10 + c);
                      y = (d * 100 + e * 10 + f);
                      z = (g * 100 + h * 10 + i);
                      printf("%d %d %d\n", x, y, z);
                    }
                  }
  return 0;
}