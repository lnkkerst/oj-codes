#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MOD = (int)1e9 + 7, MAXN = 10;

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
                    c[i][j] = (((c[i][j] % MOD + MOD) % MOD + (dataee[i][k] * b[k][j] % MOD + MOD) % MOD) + MOD) % MOD;
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

signed main() {
	int p, q, n;
	cin >> p >> q >> n;
	Mat v(2, 2);
	v[1][1] = 1, v[1][2] = -1, v[2][1] = 1;
	Mat tmp = v.pow(n - 2);
	cout << ((tmp[1][1] * q + tmp[1][2] * p) % MOD + MOD) % MOD;
	return 0;
}