#include<bits/stdc++.h>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move `fast` two steps and `slow` one step until `fast` reaches the end.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // `slow` is now pointing to the middle node.
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print a linked list starting from a given node
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, size1);

    Solution solution;
    ListNode* middle1 = solution.middleNode(head1);

    cout << "Middle node and onward for list [1, 2, 3, 4, 5]: ";
    printLinkedList(middle1); 

    int arr2[] = {1, 2, 3, 4, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, size2);

    ListNode* middle2 = solution.middleNode(head2);

    cout << "Middle node and onward for list [1, 2, 3, 4, 5, 6]: ";
    printLinkedList(middle2);

    return 0;
}
