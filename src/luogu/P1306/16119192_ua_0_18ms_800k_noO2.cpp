#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#define MOD 100000000
#define MAXN 110
#define num ch - '0'
int n, k;
int read() {
    int res;
    char ch;
    bool flag = 0;
    while(!isdigit(ch = getchar()))
        (ch == '-') && (flag = true);
    for(res = num; isdigit(ch = getchar()); res = res * 10 + num);
    (flag) && (res =-res);
    return res;
}

void print(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

struct Matrix{
    int n,m;
    int a[MAXN][MAXN];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix(int _n,int _m){
        n=_n;
        m=_m;
        memset(a,0,sizeof(a));
    }
    int* operator [] (int x){
        return a[x];
    }
    Matrix operator * (Matrix b){
        Matrix c(n,b.m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b.m;j++){
                for(int k=1;k<=m;k++){
                    c[i][j]+=(a[i][k]*b[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};
struct mat {
    int a[3][3];
    int r, c;
    int* operator [] (int x) {
        return a[x];
    }
};
mat mul(mat x, mat y) {
    mat tmp;
    memset(&tmp, 0, sizeof(tmp));
    for(int i = 0; i < x.r; ++i)
        for(int j = 0; j < y.c; j++)
            for(int k = 0; k < x.c; k++)
                tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;
    tmp.r = x.r;
    tmp.c = y.c;
    return tmp;
}
void work(int k) {
    mat p, ans;
    p.r = p.c = 2;
    p.a[0][0] = p.a[0][1] = p.a[1][0] = 1;
    ans.r = 1;
    ans.c = 2;
    ans.a[0][0] = ans[0][1] = 1;
    while(k) {
        if(k & 1)
            ans = mul(ans, p);
        p = mul(p, p);
        k >>= 1;
    }
    print(ans[0][0]);
}
int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

int main() {
    int n = read(), m = read();
    int tmp = gcd(n, m);
    if(tmp <= 2)
        print(1);
    else
        work(n - 2);
    return 0;
}