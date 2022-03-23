#include <iostream>
#include <algorithm>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update> a;
int n, x;
char opt;

int main() {
    cin >> n;
    while(n--) {
        cin >> opt >> x;
        if(opt == 'I') a.insert(x);
        else cout << *a.find_by_order(x - 1) << endl;
    }
    return 0;
}