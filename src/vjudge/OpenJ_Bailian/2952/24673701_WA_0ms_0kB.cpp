#include <iostream>
using namespace std;

int a[66], b[66];
char ch;
int n;

int main() {
    while(cin >> ch) a[++n] = ch - '0';
    if(a[1] * n > 9)
        return cout << 0, 0;
    bool fl = 1;
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) b[i] = a[i] * k;
        for(int i = n; i >= 1; --i) {
            b[i - 1] += b[i] / 10;
            b[i] %= 10;
        }
        bool fll = 0;
        for(int i = 1; i <= n; ++i) {
            int pos = i;
            for(int j = 1; j <= n; ++j) {
                if(a[j] != b[pos]) break;
                if(pos == n) pos = 1;
                else ++pos;
            }
            if(pos == i && b[pos] == a[n])
                fll = 1;
        }
        if(!fll) fl = 0;
    }
    cout << fl;
    return 0;
}