class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.length()) return 0;
        int ret = haystack.find(needle);
        if(ret == haystack.npos) return -1;
        return ret;
    }
};