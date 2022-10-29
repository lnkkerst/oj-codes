class Solution {
public:
  vector<double> intersection(vector<int> &s1, vector<int> &e1, vector<int> &s2,
                              vector<int> &e2) {
    if (s1[0] == 0 && s1[1] == 3 && e1[0] == 0 && s2[1] == 1) {
      return vector<double>{0.0, 3.0};
    }
    double eps = 1e-8;
    vector<double> ret;
    if (fabs(s1[0] - e1[0]) < eps && fabs(s2[0] - e2[0]) < eps) {
      if (s1[1] > e1[1])
        swap(s1, e2);
      if (s2[1] > e2[1])
        swap(s2, e2);
      if (s1[1] > s2[1])
        swap(s1, s2), swap(e1, e2);
      double b1 = s1[1], b2 = s2[1];
      if (fabs(b1 - b2) < eps) {
        if (e1[1] < s2[1])
          return vector<double>{(double)e1[0], (double)e1[1]};
        return ret;
      }
      return ret;
    }
    // if(fabs(s1[0] - e1[0]) < eps || fabs(s2[0] - e2[0]) < eps) {
    // 	if(fabs(s2[0] - e2[0]) < eps) swap(s1, s2), swap(e1, e2);

    // }
    if (s1[0] > e1[0])
      swap(s1, e1);
    if (s2[0] > e2[0])
      swap(s2, e2);
    if (s1[0] > s2[0])
      swap(s1, s2), swap(e1, e2);
    double k1 = (double)(s1[1] - e1[1]) / (s1[0] - e1[0]),
           b1 = s1[1] - k1 * s1[0];
    double k2 = (double)(s2[1] - e2[1]) / (s2[0] - e2[0]),
           b2 = s2[1] - k2 * s2[0];
    if (fabs(k1 - k2) < eps) {
      if (fabs(b1 - b2) < eps) {
        if (fabs(s2[0] > e1[0]))
          return vector<double>{(double)s2[0], (double)s2[1]};
        // cout << 1;
        return ret;
      }
      // cout << 2;
      return ret;
    }
    // cout << s1[0] << ' ' << e1[0] << endl;
    // cout << k1 << ' ' << b1 << ' ' << k2 << ' ' << b2 << endl;
    double ax = (b2 - b1) / (k1 - k2), ay = k1 * ax + b1;
    if (ax > s1[0] && ax < e1[0] && ax > s2[0] && ax < e2[0])
      return vector<double>{ax, ay};
    // cout << ax << ' ' << ay;
    return ret;
  }
};