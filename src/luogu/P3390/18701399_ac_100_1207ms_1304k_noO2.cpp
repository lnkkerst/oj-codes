#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define MAXN 110
#define MOD 1000000007
#define int long long

using namespace std;

struct Mat {
    int n, m;
    int dataee[MAXN][MAXN];
    Mat() {
        memset(dataee, 0, sizeof(dataee));
    }
    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        memset(dataee, 0, sizeof(dataee));
    }
    int* operator [] (int x) {
        return dataee[x];
    }
    Mat operator * (Mat b) {
        Mat c(n, b.m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= b.m; ++j)
                for(int k = 1; k <= m; ++k)
                    c[i][j] = (c[i][j] % MOD + dataee[i][k] * dataee[k][j] % MOD) % MOD;
        return c;
    }
} ;

struct Mats {
    int n;
    int dataee[MAXN][MAXN];
    Mats() {
        memset(dataee, 0, sizeof(dataee));
    }
    Mats(int _n) {
        n = _n;
        memset(dataee, 0, sizeof(dataee));
    }
    int* operator [] (int x) {
        return dataee[x];
    }
    Mats operator * (Mats b) {
        Mats c(n);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= n; ++k)
                    c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
        return c;
    }
    Mats pow(int k) {
        Mats tmp(n), res(n);
        for(int i = 1; i <= n; res[i][i] = 1, ++i)
            for(int j = 1; j <= n; ++j)
                tmp[i][j] = dataee[i][j];
        while(k) {
            if(k & 1) res = res * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return res;
    }
} ;

int n, k;

int read() {
    int res;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch -'0');
    (flag == 1) && (res *= -1);
    return res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x *= -1;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
#undef int
int main() {
    #define int long long
    n = read();
    k = read();
    Mats a(n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = read(); 
    a = a.pow(k);
    for(int i = 1; i <= n; putchar('\n'), ++i)
        for(int j = 1; j <= n; putchar(' '), ++j)
            print(a[i][j]);
    return 0;
}