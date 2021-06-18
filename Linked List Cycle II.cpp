#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> S;
        for (; head != NULL && S.find(head) == S.end(); head = head->next)
            S.insert(head);
        return head;
    }
};