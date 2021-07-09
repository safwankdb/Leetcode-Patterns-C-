#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode dummy;
        ListNode* x = &dummy;
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        vector<ListNode*> H;
        H.reserve(n);
        for (auto list : lists)
            if (list != NULL) H.push_back(list);
        make_heap(H.begin(), H.end(), cmp);
        while (!H.empty()) {
            x->next = H.front();
            x = x->next;
            pop_heap(H.begin(), H.end(), cmp);
            H.pop_back();
            if (x->next != NULL) {
                H.push_back(x->next);
                push_heap(H.begin(), H.end(), cmp);
            }
        }
        return dummy.next;
    }
};