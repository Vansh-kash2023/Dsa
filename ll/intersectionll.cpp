#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *pointerA = headA;
        ListNode *pointerB = headB;

        while (pointerA != pointerB) {
            pointerA = (pointerA == nullptr) ? headB : pointerA->next;
            pointerB = (pointerB == nullptr) ? headA : pointerB->next;
        }

        return pointerA;
    }
};

int main() {
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode *intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);
    headA->next->next = intersect;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    Solution solution;
    ListNode *result = solution.getIntersectionNode(headA, headB);

    if (result) {
        cout << "Intersected at '" << result->val << "'" << endl;
    } else {
        cout << "No intersection" << endl;
    }

    delete headA->next->next->next; 
    delete headA->next;            
    delete headA;                  
    delete headB->next->next;      
    delete headB->next;            
    delete headB;                  

    return 0;
}