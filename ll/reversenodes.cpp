#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Helper function to reverse a linked list
        auto reverse = [](ListNode* start, ListNode* end) -> ListNode* {
            ListNode* prev = nullptr;
            ListNode* current = start;
            while (current != end) {
                ListNode* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            return prev; // New head after reversal
        };

        // Check if we have enough nodes to reverse
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head; // Not enough nodes to reverse
            node = node->next;
        }

        // Reverse the first k nodes
        ListNode* newHead = reverse(head, node);

        // Recursively process the remaining nodes
        head->next = reverseKGroup(node, k);

        return newHead;
    }
};

// Utility function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example 1
    std::vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(values1);
    int k1 = 2;
    std::cout << "Original List 1: ";
    printLinkedList(head1);
    ListNode* result1 = solution.reverseKGroup(head1, k1);
    std::cout << "Reversed in Groups of " << k1 << ": ";
    printLinkedList(result1);

    // Example 2
    std::vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createLinkedList(values2);
    int k2 = 3;
    std::cout << "Original List 2: ";
    printLinkedList(head2);
    ListNode* result2 = solution.reverseKGroup(head2, k2);
    std::cout << "Reversed in Groups of " << k2 << ": ";
    printLinkedList(result2);

    return 0;
}
