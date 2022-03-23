#include <iostream>
using namespace std;

int a[50010], n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last = 0;
    for(int i = 1; i <= n; i += 2) {
        last += a[i];
    }
    for(int i = 2; i <= n; i += 2) {
        last -= a[i];
    }
    cout << last;
    for(int i = 2; i <= n; ++i) {
        cout << ' ' << (last = a[i - 1] * 2 - last);
    }
    return 0;
}