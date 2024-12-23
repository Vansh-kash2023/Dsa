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
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        // Attach the remaining part of the list if any
        if (l1) current->next = l1;
        if (l2) current->next = l2;
        
        return dummy->next;
    }
    
    // Function to find the middle of the linked list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one element
        if (!head || !head->next) return head;
        
        // Step 1: Find the middle of the list
        ListNode* mid = findMiddle(head);
        
        // Step 2: Split the list into two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;
        
        // Step 3: Recursively sort the two halves
        left = sortList(left);
        right = sortList(right);
        
        // Step 4: Merge the two sorted halves
        return merge(left, right);
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example 1
    vector<int> values = {4, 2, 1, 3};
    ListNode* head = createList(values);
    
    cout << "Original list: ";
    printList(head);
    
    head = solution.sortList(head);
    
    cout << "Sorted list: ";
    printList(head);
    
    return 0;
}
