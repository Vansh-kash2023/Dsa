#include <iostream>
#include <stack>
#include <climits>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {
        // Initialize with an empty stack
    }

    void push(int val) {
        stack.push(val);
        // Push the minimum value so far into the minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    std::cout << "getMin(): " << minStack.getMin() << std::endl; // Output: -3

    minStack.pop();

    std::cout << "top(): " << minStack.top() << std::endl; // Output: 0
    std::cout << "getMin(): " << minStack.getMin() << std::endl; // Output: -2

    return 0;
}
