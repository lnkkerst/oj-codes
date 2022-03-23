#include <iostream>
using namespace std;

int n, a[100010], ans;
bool b[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        if(!b[i]) {
            ++ans;
            b[i] = 1;
            int last = a[i];
            for(int j = i; j <= n; ++j) {
                if(!b[j] && a[j] > last) {
                    b[j] = 1;
                    last = a[j];
                }
            }
        }
    }
    cout << ans;
    return 0;
}
