#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Definition for the ListNode class
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // Copy the value of the next node
        ListNode* temp = node->next; // Store the next node
        node->next = node->next->next; // Link to skip the next node
        delete temp; // Free memory of the skipped node
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to find a node in the list by value
ListNode* findNode(ListNode* head, int value) {
    ListNode* current = head;
    while (current != NULL) {
        if (current->val == value) return current;
        current = current->next;
    }
    return NULL;
}

// Example usage
int main() {
    // Create a linked list: 3 -> 4 -> 5 -> 2 -> 6 -> 1 -> 9
    vector<int> values = {3, 4, 5, 2, 6, 1, 9};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    // Find the node with value 2
    ListNode* nodeToDelete = findNode(head, 2);
    if (nodeToDelete) {
        Solution().deleteNode(nodeToDelete);

        cout << "List after deleting node with value 2: ";
        printList(head);
    } else {
        cout << "Node not found in the list." << endl;
    }

    // Free remaining nodes (clean up memory)
    ListNode* current = head;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
