#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define MAXN 110
#define MOD 11000000007

using namespace std;

int read() {
    int res;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch -'0');
    (flag == 1) && (res *= -1);
    return res;
}

int n, k;

struct Mat {
    int n, m;
    int a[MAXN][MAXN];
    // Mat() {
    //     memset(a, 0, sizeof(a));
    // }
    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        memset(a, 0, sizeof(a));
    }
    int* operator [] (int x) {
        return a[x];
    }
    Mat operator *(Mat b) {
        Mat c(n, n);
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
        return c;
    }
} ;

Mat ksm(Mat a, int k) {
    Mat res(n, n);
    for(int i = 1; i <= n; i++)
        res[i][i] = 1;
    while(k) {
        if(k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

int main() {
    n = read();
    k = read();
    
    Mat a(n, n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            a[i][j] = read();
    ksm(a, k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d",a[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}