#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // Empty list or single node without cycle

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // Move slow by one step
            fast = fast->next->next;    // Move fast by two steps

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};

// Helper function to create a linked list with a cycle
ListNode* createCycleList(const vector<int>& values, int pos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleNode = nullptr;

    for (size_t i = 0; i < values.size(); ++i) {
        ListNode* newNode = new ListNode(values[i]);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        if (i == pos) {
            cycleNode = newNode;
        }
    }

    if (tail && cycleNode) {
        tail->next = cycleNode; // Create the cycle
    }

    return head;
}

// Helper function to free memory (handles lists without cycles)
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Example 1: List with a cycle
    vector<int> values1 = {3, 2, 0, -4};
    int pos1 = 1; // The tail connects to the node at index 1
    ListNode* head1 = createCycleList(values1, pos1);
    cout << "Example 1: " << (solution.hasCycle(head1) ? "Cycle detected" : "No cycle") << endl;

    // Example 2: List without a cycle
    vector<int> values2 = {1, 2};
    int pos2 = -1; // No cycle
    ListNode* head2 = createCycleList(values2, pos2);
    cout << "Example 2: " << (solution.hasCycle(head2) ? "Cycle detected" : "No cycle") << endl;

    // Free memory for non-cyclic list
    freeList(head2);

    return 0;
}
