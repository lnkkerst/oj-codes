#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    cout << c / min(a, b);
    return 0;
}