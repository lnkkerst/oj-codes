#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double p1x, p2x, p1y, p2y;
    cin >> p1x >> p1y >> p2x >> p2y;
    if(fabs(p1x - p2x) < 1e-8) {
        int t;
        cin >> t;
        while(t--) {
            double x, y;
            cin >> x >> y;
            printf("%.8f %.8f\n", p1x, y);
        }
    }
    else if(fabs(p1y - p2y) < 1e-8) {
        int t;
        cin >> t;
        while(t--) {
            double x, y;
            cin >> x >> y;
            printf("%.8f %.8f\n", x, p1y);
        }
    }
    else {
        double k = (p1y - p2y) / (p1x - p2x);
        double b = p1y - p1x * k;
        int t;
        cin >> t;
        cout << k << ' ' << b << endl;
        while(t--) {
            double x, y;
            cin >> x >> y;
            double a = y - -1 / k * x;
            double ansa = ((a - b) * k) / (k * k + 1);
            printf("%.8f %.8f\n", ansa, ansa * k + b);
        }
    }
    return 0;
}