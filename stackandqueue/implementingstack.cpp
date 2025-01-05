#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Two queues for the implementation

public:
    MyStack() {}

    void push(int x) {
        q2.push(x); // Push to the secondary queue
        // Transfer all elements from q1 to q2 to reverse the order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap the queues
        swap(q1, q2);
    }

    int pop() {
        int topElement = q1.front(); // Get the top element
        q1.pop();                    // Remove it from the queue
        return topElement;
    }

    int top() {
        return q1.front(); // Return the top element
    }

    bool empty() {
        return q1.empty(); // Check if the queue is empty
    }
};

int main() {
    MyStack myStack;
    
    myStack.push(1);
    myStack.push(2);
    
    cout << "Top element: " << myStack.top() << endl; // Output: 2
    
    cout << "Popped element: " << myStack.pop() << endl; // Output: 2
    
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; // Output: No

    return 0;
}
