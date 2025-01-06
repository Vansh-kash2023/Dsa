#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack_in;
    stack<int> stack_out;

    // Helper function to transfer elements from stack_in to stack_out
    void transfer() {
        while (!stack_in.empty()) {
            stack_out.push(stack_in.top());
            stack_in.pop();
        }
    }

public:
    MyQueue() { }
    
    // Push element x to the back of the queue
    void push(int x) {
        stack_in.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        if (stack_out.empty()) {
            transfer();
        }
        int top = stack_out.top();
        stack_out.pop();
        return top;
    }
    
    // Get the front element
    int peek() {
        if (stack_out.empty()) {
            transfer();
        }
        return stack_out.top();
    }
    
    // Returns true if the queue is empty
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};


int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2]
    int peek = myQueue.peek(); // return 1
    int popped = myQueue.pop(); // return 1, queue is [2]
    bool isEmpty = myQueue.empty(); // return false

    return 0;
}
