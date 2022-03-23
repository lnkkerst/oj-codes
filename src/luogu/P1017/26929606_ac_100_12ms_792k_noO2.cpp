#include <cstdio>
#include <cctype>

char biao[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75};

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

void solve(int n, int k) {
    if(n == 0) return ;
    if(n > 0 || !(n % k)) {
        solve(n/k, k);
        printf("%c", biao[n % k]);
        return ;
    }
    else {
        solve(n / k + 1, k);
        printf("%c", biao[-k + n % k]);
        return ;
    }
}

int main() {
    int n = read(), k = read();
    printf("%d=", n);
    solve(n, k);
    printf("(base%d)", k);
    return 0;
}