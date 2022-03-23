#include <cstdio>
#include <cctype>
using namespace std;
 
char s[500010];
int n, fa[500010];
char pros[500010];

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

int work(int x) {
    int ret = 0;
    int len = 0;
    int now = x;
    while(now) {
        pros[++len] = s[now];
        now = fa[now];
    }
    for(int i = len; i >= 1; --i) {
        int count = 0;
        for(int j = i; j >= 1; --j) {
            if(pros[j] == '(') ++count;
            else {
                if(count == 0) break;
                --count;
            }
            if(!count) ++ret;
        }
    }
    return ret;
}
 
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        char ch = getchar();
        while(ch != '(' && ch != ')')
            ch = getchar();
        s[i] = ch;
    }
    for(int i = 2; i <= n; ++i) fa[i] = read();
    int ans = 0;
    for(int i = 2; i <= n; ++i)
        ans ^= i * work(i);
    print(ans);
    return 0;
}