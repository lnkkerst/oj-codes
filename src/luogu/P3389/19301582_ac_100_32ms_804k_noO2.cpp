#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

double eps = 1e-7;

int read() {
    int res;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch - '0');
    return flag ? -res : res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x *= -1;
    }
    if(x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

struct Mat {
    double dat[110][110];
    int n, m;
    Mat() {
        memset(dat, 0, sizeof(dat));
    }
    Mat(int _n, int _m) {
        n = _n;
        m = _m;
        memset(dat, 0, sizeof(dat));
    }
    Mat(int _gu) {
        n = _gu;
        m = _gu + 1;
        memset(dat, 0, sizeof(dat));
    }
    double* operator [] (int x) {
        return dat[x];
    }
    double x[110];
    bool gauss() {
        for(int i = 1, pos; i <= n; ++i) {
            pos = i;
            for(int j = i + 1; j <= n; ++j)
                if(fabs(dat[j][i]) > fabs(dat[pos][i]))
                    pos = j;
            for(int j = i; j <= n + 1; ++j) swap(dat[pos][j], dat[i][j]);
            if(!dat[i][i])
                return false;
            for(int j = i + 1; j <= n; ++j)
                if(fabs(dat[j][i]) > eps) {
                    double p = dat[i][i] / dat[j][i];
                    for(int k = i; k <= n + 1; ++k) dat[j][k] = dat[i][k] - dat[j][k] * p;
                }
        }
        for(int i = n; i >= 1; --i) {
            x[i] = dat[i][n + 1];
            for(int j = i + 1; j <= n; ++j) x[i] -= x[j] * dat[i][j];
            x[i] /= dat[i][i];
        }
        return true;
    }
} ;

int main() {
    int n = read();
    Mat ans(n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n + 1; ++j)
            ans[i][j] = read();
    if(ans.gauss())
        for(int i = 1; i <= n; ++i)
            printf("%.2lf\n", ans.x[i]);
    else
        puts("No Solution");
    return 0;
}