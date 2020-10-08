#include <iostream>
#include <algorithm>
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* prev = head;
        ListNode* end = prev->next;

        while (end->next != NULL) {
            prev = prev->next;
            end = end->next;
        }

        prev->next = NULL;

        end->next = head->next;
        head->next = end;
        
        
        reorderList(end->next);
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next= new ListNode(5);
    Solution S;
    S.reorderList(head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}
