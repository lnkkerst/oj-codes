// #include <cstdio>
// #include <cctype>
// #include <algorithm>
// #include <cstring>
// #define MAXN 10
// #define MOD 1000000007
// #define int long long

// using namespace std;

// struct Mat {
//     int n, m;
//     int dataee[MAXN][MAXN];
//     Mat() {
//         memset(dataee, 0, sizeof(dataee));
//     }
//     Mat(int _n, int _m) {
//         n = _n;
//         m = _m;
//         memset(dataee, 0, sizeof(dataee));
//     }
//     int* operator [] (int x) {
//         return dataee[x];
//     }
//     Mat operator * (Mat b) {
//         Mat c(n, b.m);
//         for(int i = 1; i <= n; ++i)
//             for(int j = 1; j <= b.m; ++j)
//                 for(int k = 1; k <= m; ++k)
//                     c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
//         return c;
//     }
//     Mat pow(int k) {
//         Mat tmp(n, n), res(n, n);
//         for(int i = 1; i <= n; res[i][i] = 1, ++i)
//             for(int j = 1; j <= n; ++j)
//                 tmp[i][j] = dataee[i][j];
//         while(k) {
//             if(k & 1) res = res * tmp;
//             tmp = tmp * tmp;
//             k >>= 1;
//         }
//         return res;
//     }
// } ;

// int n, k;

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
//     int t = read();
//     Mat v(3, 3);
//     v[1][1] = v[1][3] = v[2][1] = v[3][2] = 1;
//     while(t--) {
//         Mat tmp = v.pow(read() - 1);
//         print(tmp[1][1]);
//         putchar('\n');
//     }
//     return 0;
// }

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define MAXN 10
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
                    c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
        return c;
    }
    Mat pow(int k) {
        Mat tmp(n, n), res(n, n);
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
    int p = read(), q = read(), a1 = read(), a2 = read(), n = read(), m = read();
    if(n == 1) {
        print(a1);
        putchar('\n');
        return 0;
    }
    if(n == 2) {
        print(a2);
        putchar('\n');
        return 0;
    }
    Mat v(2, 2);
    v[1][1] = p;
    v[2][1] = q;
    v[1][2] = 1;
    Mat tmp = v.pow(n - 1);
    print(tmp[1][1] % m);
    putchar('\n');
    return 0;
}