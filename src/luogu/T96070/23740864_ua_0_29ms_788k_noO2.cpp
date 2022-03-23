#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>

using namespace std;

int read() {
    int ret;
    char ch;
    bool f;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return f ? -ret : ret;
}

void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) {
		print(x / 10);
	}
	putchar(x % 10 + '0');
	return ;
}

int main() {
	print(ceil((double)read() / 2));
	return 0;
}