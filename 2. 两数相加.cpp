#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *res = new ListNode();
        ListNode *p = res;
        int h = 0;
        do {
            if (l1 == nullptr) {
                p->val = (l2->val + h) % 10;
                h = (l2->val + h) / 10;
                if (l2->next == nullptr) {
                    if (h != 0) {
                        p->next = new ListNode(h);
                    }
                    break;
                }
                l2 = l2->next;
                p->next = new ListNode();
                p = p->next;
                continue;
            }
            if (l2 == nullptr) {
                p->val = (l1->val + h) % 10;
                h = (l1->val + h) / 10;
                if (l1->next == nullptr) {
                    if (h != 0) {
                        p->next = new ListNode(h);
                    }
                    break;
                }
                l1 = l1->next;
                p->next = new ListNode();
                p = p->next;
                continue;
            }
            p->val = (l1->val + l2->val + h) % 10;
            h = (l1->val + l2->val + h) / 10;
            if (l1->next == nullptr && l2->next == nullptr) {
                if (h != 0) {
                    p->next = new ListNode(h);
                }
                break;
            }
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
            p->next = new ListNode();
            p = p->next;
        } while (true);
        return res;
    }
};