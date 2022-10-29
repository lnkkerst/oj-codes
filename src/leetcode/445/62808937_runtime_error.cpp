/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    long long a = 0, b = 0;
    ListNode *p = l1;
    while (p != NULL) {
      a *= 10;
      a += p->val;
      p = p->next;
    }
    p = l2;
    while (p != NULL) {
      b *= 10;
      b += p->val;
      p = p->next;
    }
    string s = to_string(a + b);
    p = new ListNode;
    ListNode *ret = p;
    for (auto i : s) {
      p->next = new ListNode(i - '0');
      p = p->next;
    }
    return ret->next;
  }
};