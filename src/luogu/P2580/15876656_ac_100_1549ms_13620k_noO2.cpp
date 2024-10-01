#include <iostream>
#include <map>
std::map<std::string, int> mp;
std::string s;
int n;
int main() {
  std::cin >> n;
  while (n--) {
    std::cin >> s;
    mp[s] = 1;
  }
  std::cin >> n;
  while (n--) {
    std::cin >> s;
    if (mp[s] == 1) {
      std::cout << "OK\n";
      mp[s] = 2;
    } else if (mp[s] == 2) {
      std::cout << "REPEAT\n";
    } else {
      std::cout << "WRONG\n";
    }
  }
  return 0;
}
