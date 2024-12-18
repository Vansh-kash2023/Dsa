#include <bits/stdc++.h>
using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory of the removed node
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

// Helper functions to work with linked lists
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test case 1
    vector<int> values1 = {1, 1, 2};
    ListNode* list1 = createLinkedList(values1);
    cout << "Original List 1: ";
    printLinkedList(list1);
    ListNode* result1 = solution.deleteDuplicates(list1);
    cout << "Updated List 1: ";
    printLinkedList(result1);
    freeLinkedList(result1);

    // Test case 2
    vector<int> values2 = {1, 1, 2, 3, 3};
    ListNode* list2 = createLinkedList(values2);
    cout << "Original List 2: ";
    printLinkedList(list2);
    ListNode* result2 = solution.deleteDuplicates(list2);
    cout << "Updated List 2: ";
    printLinkedList(result2);
    freeLinkedList(result2);

    return 0;
}
