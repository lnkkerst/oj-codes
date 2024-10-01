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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *ret = new ListNode(-1), *tail = ret;
    vector<int> q;
    while (head) {
      bool fl = true;
      for (int i = 1; head && i <= k; ++i) {
        q.push_back(head->val);
        head = head->next;
        if (!head) {
          fl = false;
        }
      }
      if (fl) {
        for (auto i = q.rbegin(); i != q.rend(); ++i) {
          tail->next = new ListNode(*i);
          tail = tail->next;
        }
      } else {
        for (auto i = q.begin(); i != q.end(); ++i) {
          tail->next = new ListNode(*i);
          tail = tail->next;
        }
      }
      q.clear();
    }
    return ret->next;
  }
};
