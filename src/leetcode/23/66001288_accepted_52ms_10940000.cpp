class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(auto i : lists) {
            while(i) {
                q.push(i->val);
                i = i->next;
            }
        }
        ListNode *ret = new ListNode(-1), *tail = ret;
        while(!q.empty()) {
            tail->next = new ListNode(q.top());
            tail = tail->next;
            q.pop();
        }
        return ret->next;
    }
};
