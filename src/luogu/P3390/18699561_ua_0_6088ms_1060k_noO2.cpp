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
    int a[MAXN][MAXN];
    int* operator [] (int x) {
        return a[x];
    }
} ;

Mat mul(Mat a, Mat b) {
    Mat c;
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
    return c;
}

Mat ksm(Mat a, int k) {
    Mat res;
    for(int i = 1; i <= n; i++)
        res[i][i] = 1;
    while(k) {
        if(k & 1) res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}

int main() {
    n = read();
    k = read();
    
    Mat a;
    memset(a.a, 0, sizeof(0));
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