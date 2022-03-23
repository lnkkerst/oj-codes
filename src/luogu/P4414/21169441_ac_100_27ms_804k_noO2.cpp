#include <cctype>
#include <cstdio>
#include <algorithm>

int read() {
    int res;
    char ch;
    bool flag = 0;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (flag = true);
    for(res = ch - '0'; isdigit(ch = getchar()); res = res * 10 + ch - '0');
    (flag) && (res =-res);
    return res;
}

void print(long long x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

char readchar() {
    char ret;
    while(!isalpha(ret = getchar()));
    return ret;
}

int a[3];

int main() {
    for(int i = 0; i < 3; ++i) a[i] = read();
    std::sort(a, a + 3);
    for(int i = 0; i < 3; ++i, putchar(' ')) print(a[readchar() - 'A']);
    return 0;
}