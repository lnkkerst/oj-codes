/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

string sum(const string &a, const string &b) {
	string na = string(a.rbegin(), a.rend());
	string nb = string(b.rbegin(), b.rend());
	int last = 0;
	string ret;
	if(na.size() < nb.size()) swap(na, nb);
	for(int i = 0; i < (int)nb.size(); ++i)
		ret.push_back((na[i] + nb[i] - 96 + last) % 10 + 48),
		last = (na[i] + nb[i] - 96 + last) / 10;
	for(int i = (int)nb.size(); i < (int)na.size(); ++i)
		ret.push_back((na[i] - 48 + last) % 10 + 48),
		last = (na[i] - 48 + last) / 10;
	if(last) ret.push_back(last + 48);
	return string(ret.rbegin(), ret.rend());
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a, b;
        ListNode* p = l1;
        while(p != NULL) {
            a.push_back(p->val + '0');
            p = p->next;
        }
        p = l2;
        while(p != NULL) {
            b.push_back(p->val + '0');
            p = p->next;
        }
        string s = sum(a, b);
        p = new ListNode;
        ListNode *ret = p;
        for(auto i : s) {
            p->next = new ListNode(i - '0');
            p = p->next;
        }
        return ret->next;
    }
};