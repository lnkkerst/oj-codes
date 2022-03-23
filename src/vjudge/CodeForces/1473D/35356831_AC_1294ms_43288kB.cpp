#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> l2(200010, -1);
    for (int i = 1; i <= 200001; ++i) {
        l2[i] = l2[i >> 1] + 1;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mi(n + 10, vector<int>(l2[n] + 5, 0)), ma = mi;
        for (int i = 1; i <= n; ++i) {
            char ch;
            cin >> ch;
            if (ch == '+') {
                ma[i][0] = mi[i][0] = ma[i - 1][0] + 1;
            } else {
                ma[i][0] = mi[i][0] = ma[i - 1][0] - 1;
            }
        }
        for (int j = 1; j < l2[n] + 1; ++j) {
            for (int i = 1; i <= n - (1 << j) + 1; ++i) {
                ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
                mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            }
        }
        const auto &qMax = [](const vector<vector<int>> &a, const vector<int> &l2, int l, int r) -> int {
            int siz = l2[r - l + 1];
            return max(a[l][siz], a[r - (1 << siz) + 1][siz]);
        };
        const auto &qMin = [](const vector<vector<int>> &a, const vector<int> &l2, int l, int r) -> int {
            int siz = l2[r - l + 1];
            return min(a[l][siz], a[r - (1 << siz) + 1][siz]);
        };
        for (int i = 1; i <= m; ++i) {
            int l, r;
            cin >> l >> r;
//            int mal = l != 1 ? max(ma[1][l2[l - 1]], ma[l - (1 << l2[l - 1])][l2[l - 1]]) : 0;
//            int mar = r != n ? max(ma[r + 1][l2[n - r]], ma[n - (1 << l2[n - r]) + 1][l2[n - r]]) : 0;
//            int mil = l != 1 ? min(mi[1][l2[l - 1]], mi[l - (1 << l2[l - 1])][l2[l - 1]]) : 0;
//            int mir = r != n ? min(mi[r + 1][l2[n - r]], mi[n - (1 << l2[n - r]) + 1][l2[n - r]]) : 0;
            int mal = l != 1 ? qMax(ma, l2, 1, l - 1) : 0;
            int mar = r != n ? qMax(ma, l2, r + 1, n) : 0;
            int mil = l != 1 ? qMin(mi, l2, 1, l - 1) : 0;
            int mir = r != n ? qMin(mi, l2, r + 1, n) : 0;
            mal = max(mal, 0);
            mil = min(mil, 0);
            if (r == n) {
                cout << mal - mil + 1 << endl;
            } else if (l == 1) {
                int dif = 0 - ma[r][0];
                mar += dif;
                mir += dif;
                mar = max(0, mar);
                mir = min(0, mir);
                cout << mar - mir + 1 << endl;
            } else {
                int dif = ma[l - 1][0] - ma[r][0];
                mar += dif;
                mir += dif;
                if(mal < mir || mar < mil) {
                    cout << mal - mil + 1 + mar - mir + 1 << endl;
                } else {
                    cout << max(mal, mar) - min(mil, mir) + 1 << endl;
                }
            }
        }
    }
}