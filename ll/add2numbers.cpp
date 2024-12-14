#include<bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummy->next;
    }
};

ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> list1 = {2, 4, 3}; 
    vector<int> list2 = {5, 6, 4};

    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

    cout << "Input List 1: ";
    printLinkedList(l1);
    cout << "Input List 2: ";
    printLinkedList(l2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result List: ";
    printLinkedList(result);

    return 0;
}
