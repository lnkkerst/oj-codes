class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<int> q;
    for (auto i : lists) {
      while (i) {
        q.push_back(i->val);
        i = i->next;
      }
    }
    ListNode *ret = new ListNode(-1), *tail = ret;
    sort(q.begin(), q.end());
    for (auto i : q) {
      tail->next = new ListNode(i);
      tail = tail->next;
    }
    return ret->next;
  }
};
