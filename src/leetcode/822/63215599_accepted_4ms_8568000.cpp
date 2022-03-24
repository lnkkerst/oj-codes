class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> e{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> b;
        for(auto i : words) {
            string t;
            for(auto j : i)
                t += e[j - 'a'];
            b.insert(t);
        }
        return b.size();
    }
};