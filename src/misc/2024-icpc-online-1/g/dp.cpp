#include <cstdio>
#include <cstdlib>
#include <ctime>
int main() {
  for (int T = 1; T <= 10000; ++T) {
    system("python dm.py > indp");
    system("1.exe < indp > outdp1");
    system("bl.exe < indp > outbl");
    if (system("fc outdp1 outbl")) {
      return 0;
    }
  }
}
