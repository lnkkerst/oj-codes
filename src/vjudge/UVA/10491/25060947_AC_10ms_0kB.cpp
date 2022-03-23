#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        double t = a + b - 1;
        cout << fixed << setprecision(5) << t * b / (t + 1) / (t - c) << endl;
    }
    return 0;
}