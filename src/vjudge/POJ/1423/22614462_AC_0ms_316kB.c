#include <stdio.h>
#include <math.h>
const double PI = 3.1415926535;
const double E = 2.71828182846;

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

int calc(int x) {
	return x > 3 ? (log10(x * 2 * PI) / 2 + x * log10(x / E) + 1) : 1;
}

int main() {
	int t = read();
	while(t--) print(calc(read())), putchar('\n');
	return 0;
}