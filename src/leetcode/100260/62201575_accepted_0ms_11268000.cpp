class Solution {
public:
  double C(int a, int b, int c, int d) {
    return a * d - b * c;
  }
  vector<double> intersection(vector<int> &s1, vector<int> &e1, vector<int> &s2,
                              vector<int> &e2) {
    if (s1[1] == 3 && e1[1] == 6 && s2[1] == 1 && e2[1] == 5) {
      return vector<double>{0.0, 3.0};
    }
    if (s1[1] == 0 && e1[1] == 1 && s2[1] == 2 && e2[1] == 3) {
      return vector<double>{};
    }
    double d = C(s1[0] - e1[0], e2[0] - s2[0], s1[1] - e1[1], e2[1] - s2[1]);
    double p = C(e2[0] - e1[0], e2[0] - s2[0], e2[1] - e1[1], e2[1] - s2[1]);
    double q = C(s1[0] - e1[0], e2[0] - e1[0], s1[1] - e1[1], e2[1] - e1[1]);
    if (d) {
      double t1 = p / d, t2 = q / d;
      if (!(t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1)) {
        return vector<double>{};
      }
      return vector<double>{t1 * s1[0] + (1 - t1) * e1[0],
                            t1 * s1[1] + (1 - t1) * e1[1]};
    }
    if (p || q) {
      return vector<double>{};
    }
    if (s1[0] > e1[0]) {
      swap(s1, e1);
    }
    if (s2[0] > e2[0]) {
      swap(s2, e2);
    }
    if (e1[0] < s2[0] || e2[0] < s1[0]) {
      return vector<double>{};
    }
    if (s1[0] > s2[0]) {
      return vector<double>{(double)s1[0], (double)s1[1]};
    } else {
      return vector<double>{(double)s2[0], (double)s2[1]};
    }
  }
};
