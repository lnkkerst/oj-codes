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
    int n = read();
    double ans = 420000.00;
    for(int i = 2; i <= n; i++)
        ans = ans * (i * 2 - 1) / (i * 2);
    printf("%.2lf\n", ans);
    return 0;
}