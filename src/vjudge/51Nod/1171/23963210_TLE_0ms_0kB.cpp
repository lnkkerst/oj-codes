#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#define int long long

const double eps = 1e-9;
int n;
bool fl = 0;

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

signed main() {
	n = read();
	int maxran = (int)sqrt((double)n / 2.0);
	for(int i = 1; i <= maxran; ++i) {
		int t = (int)sqrt((double)n - (double)(i * i));
		if(t * t + i * i == n) print(i), putchar(' '), print(t), putchar('\n'), fl = 1;
	}
    if(!fl) printf("No Solution\n");
	return 0;
}