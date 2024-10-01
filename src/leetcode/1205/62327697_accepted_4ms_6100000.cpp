class Solution {
public:
  string defangIPaddr(string address) {
    int pos = address.find(".");
    while (pos != string::npos) {
      address.erase(pos, 1);
      address.insert(pos, "[.]");
      pos = address.find(".", pos + 3);
    }
    return address;
  }
};
