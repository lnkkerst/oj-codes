#include <iostream>
using namespace std;

int n;
int a[100001];
int aa[100001];
bool b[100001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(b[a[i]] || a[i] > n) a[i] = 0;
        if(a[i] <= n) b[a[i]] = true;
    }
    int pos[100001];
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(!b[i]) pos[++cnt] = i;
    cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(!a[i]) a[i] = pos[++cnt];
    for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}