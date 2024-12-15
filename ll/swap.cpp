#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* pairsSwap(Node *head) {
    if (!head || !head->next) {
        // If the list is empty or has only one node, return head.
        return head;
    }

    Node* newHead = head->next; // The second node will become the new head.
    Node* prev = nullptr;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        // Swapping the two nodes
        first->next = second->next;
        second->next = first;

        if (prev) {
            // Link the previous pair to the current swapped pair
            prev->next = second;
        }

        // Move to the next pair
        prev = first;
        head = first->next;
    }

    return newHead;
}

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, n);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = pairsSwap(head);

    cout << "Swapped Linked List: ";
    printLinkedList(head);

    return 0;
}
