// #include <cstdio>
// #include <cctype>
// #include <algorithm>
// #include <cstring>
// #define MAXN 500
// #define int long long

// using namespace std;

// int read();
// void print(int x);

// int MOD, n, k, d;

// struct Mat {
//     int n;
//     int dataee[MAXN];
//     Mat() {
//         memset(dataee, 0, sizeof(dataee));
//     }
//     Mat(int _n) {
//         n = _n;
//         memset(dataee, 0, sizeof(dataee));
//     }
//     int operator [] (int x) {
//         return dataee[x];
//     }
//     Mat operator * (Mat b) {
//         Mat c(n);
//         for(int i = 1; i <= n; ++i)
//             for(int j = 1; j <= n; ++j)
//                     c[i] = (c[i] % MOD + dataee[j] * b[(i - j + n) % n] % MOD) % MOD;
//         return c;
//     }
//     Mat pow(int k) {
//         Mat tmp(n), res(n);
//         for(int i = 1; i <= n; res[i] = 1, ++i)
//                 tmp[i] = dataee[i];
//         while(k) {
//             if(k & 1) res = res * tmp;
//             tmp = tmp * tmp;
//             k >>= 1;
//         }
//         return res;
//     }
// } ;

// int read() {
//     int res;
//     bool flag = 0;
//     char ch;
//     while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
//     for(res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch -'0');
//     (flag == 1) && (res *= -1);
//     return res;
// }

// void print(int x) {
//     if(x < 0) {
//         putchar('-');
//         x *= -1;
//     }
//     if(x > 9)
//         print(x / 10);
//     putchar(x % 10 + '0');
// }

// #undef int
// int main() {
//     #define int long long
//     n = read();
//     MOD = read();
//     d = read();
//     k = read();
//     Mat a(n);
//     Mat vi(n);
//     vi[1] = 1;
//     for(int i = 1; i <= d; ++i) vi[1][i + 1] = 1, vi[1][n + 1 - i] = 1;    for(int i = 2; i <= n; ++i)
//         for(int j = 1; j <= n; ++j)
//             vi[i][j] = vi[1][(i - j + n) % n + 1];
//     for(int i = 1; i <= n; ++i) a[i] = read();
//     Mat ans = vi.pow(k);
//     ans = ans * a;
//     return 0;
// }


#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define MAXN 550
#define int long long

using namespace std;

int read();
void print(int x);

int MOD, n, k, d;

struct Mat {
    int n;
    int data[MAXN];
    Mat() {
        memset(data, 0, sizeof(data));
    }
    Mat (int _n) {
        n = _n;
        memset(data, 0, sizeof(data));
    }
    Mat operator * (Mat b) {
        Mat c(n);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                c.data[i] = (1LL * data[j] * b.data[(i - j + n) % n + 1] + c.data[i]) % MOD;
        return c;
    }
    Mat pow(int k) {
        Mat tmp(n), res(n);
        res.data[1] = 1;
        for(int i = 1; i <= n; ++i)
            tmp.data[i] = data[i];
        while(k) {
            if(k & 1) res = res * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return res;
    }
    void pri() {
        for(int i = 1; i <= n - 1; putchar(' '), i++) print(data[i]);
        print(data[n]);
        putchar('\n');
    }
} ;

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
        while(scanf("%d%d%d%d", &n, &MOD, &d, &k) != EOF) {
        Mat a(n), vi(n);
        for(int i = 1; i <= n; ++i) a.data[i] = read();
        for(int i = 0; i <= d; ++i) vi.data[i + 1] = 1, vi.data[n + 1 - i] = 1;
        Mat ans = vi.pow(k) * a;
        ans.pri();
    }
    return 0;
}
