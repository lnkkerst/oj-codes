#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#define int long long
#define MOD 100000000
#define MAXN 3
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
};
void work(int k) {
    Matrix p, ans;
    p.m = p.n = 2;
    p.a[0][0] = p.a[0][1] = p.a[1][0] = 1;
    ans.m = 1;
    ans.n = 2;
    ans.a[0][0] = ans[0][1] = 1;
    while(k) {
        if(k & 1)
            ans = ans * p;
        p = p * p;
        k >>= 1;
    }
    print(ans[0][0]);
}
int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}
#undef int
int main() {
    #define int long long
    int n = read(), m = read();
    int tmp = gcd(n, m);
    if(tmp <= 2)
        print(1);
    else
        work(n - 2);
    return 0;
}