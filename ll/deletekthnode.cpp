#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to simplify edge cases (e.g., removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Remove the nth node from the end
        second->next = second->next->next;
        
        // Return the updated head
        return dummy->next;
    }
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Test case: head = [1, 2, 3, 4, 5], n = 2
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Create the list
    ListNode* head = createList(arr, size);
    cout << "Original list: ";
    printList(head);
    
    // Apply the solution
    Solution solution;
    head = solution.removeNthFromEnd(head, n);
    
    // Print the updated list
    cout << "Updated list: ";
    printList(head);
    
    return 0;
}