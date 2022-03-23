#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Coin{
    int w, v;
    double a;
} a[110];

int n, c;
double ans = 0;

int main() {
    cin >> n >> c;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].w >> a[i].v;
        a[i].a = (double)a[i].v / a[i].w;
    }
    sort(a + 1, a + n + 1, [](Coin a, Coin b) -> bool { return a.a > b.a; });
    int pos = 1;
    while(c && pos <= n) {
        --c;
        ans += a[pos].a;
        --a[pos].w;
        if(!a[pos].w) {
            ++pos;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}