#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution class with reverseList function
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative implementation
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next; // Store the next node
            curr->next = prev;          // Reverse the current node's pointer
            prev = curr;                // Move prev forward
            curr = next;                // Move curr forward
        }
        
        return prev; // New head of the reversed list
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Example 1: Input [1,2,3,4,5]
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(values1);
    cout << "Original list: ";
    printList(head1);

    head1 = solution.reverseList(head1);
    cout << "Reversed list: ";
    printList(head1);

    // Example 2: Input [1,2]
    vector<int> values2 = {1, 2};
    ListNode* head2 = createList(values2);
    cout << "Original list: ";
    printList(head2);

    head2 = solution.reverseList(head2);
    cout << "Reversed list: ";
    printList(head2);

    // Example 3: Input []
    vector<int> values3 = {};
    ListNode* head3 = createList(values3);
    cout << "Original list: ";
    printList(head3);

    head3 = solution.reverseList(head3);
    cout << "Reversed list: ";
    printList(head3);

    return 0;
}
