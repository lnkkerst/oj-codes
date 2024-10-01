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
    ListNode *ret = new ListNode(-1), *p1 = l1, *p2 = l2, *pr = ret;
    int tmp = 0;
    while (p1 != NULL && p2 != NULL) {
      pr->next = new ListNode((p1->val + p2->val + tmp) % 10);
      tmp = (p1->val + p2->val + tmp) / 10;
      p1 = p1->next;
      p2 = p2->next;
      pr = pr->next;
    }
    while (p1 != NULL) {
      pr->next = new ListNode((p1->val + tmp) % 10);
      tmp = (p1->val + tmp) / 10;
      p1 = p1->next;
      pr = pr->next;
    }
    while (p2 != NULL) {
      pr->next = new ListNode((p2->val + tmp) % 10);
      tmp = (p2->val + tmp) / 10;
      p2 = p2->next;
      pr = pr->next;
    }
    if (tmp) {
      pr->next = new ListNode(tmp);
    }
    return ret->next;
  }
};
