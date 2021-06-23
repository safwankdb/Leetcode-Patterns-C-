#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *l = new ListNode(0, head);
        for (int i = 0; i < left - 1; i++) l = l->next;
        ListNode *prev = NULL, *x = l->next, *tmp;
        int counter = 0;
        while (x && counter <= right - left) {
            tmp = x->next;
            x->next = prev;
            prev = x;
            x = tmp;
            counter++;
        }
        l->next->next = x;
        l->next = prev;
        return (left == 1) ? prev : head;
    }
};