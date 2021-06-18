#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> S;
        for (; head != NULL && S.find(head) == S.end(); head = head->next)
            S.insert(head);
        return head;
    }
};