#include <cstdio>
#include <cctype>

inline int read() {
	int ret, f = 1;
	char ch;
	while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
	for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
	return ret * f;
}

inline void print(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	print(read() * -1 - read() * -2);
	return 0;
}