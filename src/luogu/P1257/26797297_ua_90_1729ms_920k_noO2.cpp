#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double x[10001], y[10001];
double ans = 1e9;

int read() {
    int ret, f = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * f;
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

double calc(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i == j) continue;
            else ans = min(calc(x[i], y[i], x[j], y[j]), ans);
    printf("%.4lf", ans);
    return 0;
}
