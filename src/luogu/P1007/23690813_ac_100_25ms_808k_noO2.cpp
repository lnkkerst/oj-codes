#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <map>

using namespace std;

int read() {
    int ret;
    bool f = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return f ? -ret : ret;
}

void print(int x) {
    if(x < 0) {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int l = read(), n = read(), maxans = 0, minans = 0;
    for(int i = 1; i <= n; ++i) {
        int t = read();
        maxans = max(maxans, max(t, (l + 1 - t)));
        minans = max(minans, min(t, (l + 1 - t)));
    }
    print(minans);
    putchar(' ');
    print(maxans);
    putchar('\n');
    return 0;
}