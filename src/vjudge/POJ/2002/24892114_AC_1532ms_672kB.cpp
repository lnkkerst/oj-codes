#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator< (const Point b) const {
        return this->x == b.x ? this->y < b.y : this->x < b.x;
    }
} a[1001];

int n, ans = 0;

bool search(int x, int y) {
    int l = 1, r = n + 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid].x == x  && a[mid].y == y)
            return 1;
        if(a[mid].x == x && a[mid].y < y || a[mid].x < x)
            l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    while(cin >> n) {
        if(!n) return 0;
        for(int i = 1; i <= n; ++i)
            cin >> a[i].x >> a[i].y;
        ans = 0;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int tx = a[i].x - a[j].y + a[i].y;
                int ty = a[i].y + a[j].x - a[i].x;
                bool fl = search(tx, ty);
                tx = a[j].x - a[j].y + a[i].y;
                ty = a[j].y + a[j].x - a[i].x;
                if(fl && search(tx, ty)) ++ans;
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}