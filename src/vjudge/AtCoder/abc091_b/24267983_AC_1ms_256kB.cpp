#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int n, m;
string a[101], b[101];
map<string , int > s, t;

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

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++s[a[i]];
    }
    m = read();
    for(int i = 1; i <= m; ++i) {
        cin >> b[i];
        ++t[b[i]];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int t1 = s[a[i]], t2 = t[a[i]];
        if(t1 > t2) ans = max(ans, t1 - t2), s[a[i]] = 0;
    }
    print(ans);
    return 0;
}
