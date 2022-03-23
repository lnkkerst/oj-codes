#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    if(a.length() < b.length()) swap(a, b);
    int l1 = a.length(), l2 = b.length();
    a += a, b += b;
    int size = l2;
    bool fl = 0;
    for(; size && !fl; --size) {
        for(int i = 0; i + size <= l2 * 2; ++i) {
            if(a.find(b.substr(i, size)) != a.npos) {
                fl = 1;
                break;
            }
        }
    }
    cout << size + 1;
    return 0;
}