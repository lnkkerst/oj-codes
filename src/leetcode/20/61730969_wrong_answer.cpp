class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[')
                q.push(i);
            else {
                if(q.empty()) return 0;
                if((i == ')' && q.top() == '(') || (i == '}' && q.top() == '{') || (i == '[' && q.top() == ']')) q.pop();
                else return 0;
            }
        }
        return q.empty();
    }
};