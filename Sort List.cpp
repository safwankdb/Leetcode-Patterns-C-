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
    ListNode* merge(ListNode* x, ListNode* y) {
        int n1 = 0, n2 = 0;
        ListNode dummy;
        auto h1 = x, h2 = y, d = &dummy;
        for (; h1 != NULL; n1++) h1 = h1->next;
        for (; h2 != NULL; n2++) h2 = h2->next;
        while (x != NULL && y != NULL) {
            if (x->val < y->val) {
                d->next = x;
                x = x->next;
            } else {
                d->next = y;
                y = y->next;
            }
            d = d->next;
        }
        while (x != NULL) {
            d->next = x;
            x = x->next;
            d = d->next;
        }
        while (y != NULL) {
            d->next = y;
            y = y->next;
            d = d->next;
        }
        return dummy.next;
    }

   public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        int n = 0;
        ListNode *h1 = head, *h2 = head;
        for (; head != NULL; n++) head = head->next;
        for (int i = 0; i < (n - 1) / 2; i++) h2 = h2->next;
        auto t = h2->next;
        h2->next = NULL;
        h2 = t;
        h1 = sortList(h1);
        h2 = sortList(h2);
        return merge(h1, h2);
    }
};