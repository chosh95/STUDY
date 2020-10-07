#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0);
        ListNode* cur = answer;

        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(carry%10);
            cur = cur->next;

            carry /= 10;
        }

        return answer->next;
    }
};