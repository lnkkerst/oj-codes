#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct student {
  string name;
  int state;
} stu[5];
int main() {
  int n, i, j, ans, t = 0;
  int tflag = 0;
  string tea[3], event, ename, ansn[5];
  cin >> n;
  for (i = 0; i < 3; i++) {
    cin >> tea[i];
  }
  for (i = 0; i < 5; i++) {
    cin >> stu[i].name;
    stu[i].state = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> ename;
    getline(cin, event);
    if (event == " started playing games!") {
      for (j = 0; j < 5; j++) {
        if (stu[j].name == ename) {
          if (stu[j].state == 2) {
            break;
          } else if (tflag != 0) {
            stu[j].state = 2;
            ans++;
            ansn[t] = stu[j].name;
            t++;
            break;
          } else {
            stu[j].state = 1;
          }
          break;
        }
      }
    } else if (event == " stopped playing games!") {
      for (j = 0; j < 5; j++) {
        if (stu[j].name == ename) {
          if (stu[j].state == 2) {
            break;
          } else {
            stu[j].state = 1;
          }
          break;
        }
      }
    } else if (event == " came!") {
      for (j = 0; j < 3; j++) {
        if (tea[j] == ename) {
          tflag++;
          for (j = 0; j < 5; j++) {
            if (stu[j].state == 1) {
              ans++;
              ansn[t] = stu[j].name;
              t++;
            }
          }
          break;
        }
      }
    } else if (event == " left!") {
      for (j = 0; j < 3; j++) {
        if (tea[j] == ename) {
          tflag--;
          break;
        }
      }
    }
  }
  sort(ansn, ansn + ans);
  for (i = 0; i < ans; i++) {
    cout << ansn[i] << " ";
  }
  if (ans == 5) {
    cout << endl << "How Bad Oiers Are!";
  } else if (ans == 0) {
    cout << "How Good Oiers Are!";
  }
  return 0;
}
