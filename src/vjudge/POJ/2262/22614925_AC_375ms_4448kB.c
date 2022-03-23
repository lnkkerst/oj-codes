#include <stdio.h>
#define MAXN 1000001

int prime[MAXN], cnt = 0;
int IsNotprime[MAXN];

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

void sieve() {
    IsNotprime[1] = 1;
    for(int i = 2; i <= MAXN; i++) {
        if(!IsNotprime[i]) {
            prime[++cnt] = i;
            for(int j = i * 2; j <= MAXN; j += i)
                IsNotprime[j] = 1;
        }
    }
}
int main() {
    sieve();
    while(233) {
        int t = read();
        if(!t) return 0;
        for(int i = 1; prime[i] <= t; ++i)
            if(!IsNotprime[t - prime[i]]) {
                printf("%d = %d + %d\n", t, prime[i], t - prime[i]);
                break;
            }
    }
}