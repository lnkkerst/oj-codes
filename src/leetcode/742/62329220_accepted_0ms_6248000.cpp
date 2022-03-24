class Solution {
public:
    string toLowerCase(string str) {
        string ret;
        for(auto i : str)
            ret.push_back(tolower(i));
        return ret;
    }
};