#include <iostream>
#include <stack>

using namespace std;

class Stack {
private:
    stack<int> st;

public:
    // Check if the stack is empty
    bool isEmpty() {
        return st.empty();
    }

    // Get the total number of elements in the stack
    int getSize() {
        return st.size();
    }

    // Push an element onto the top of the stack
    void push(int value) {
        st.push(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    // Get the value of the top element
    int top() {
        if (!st.empty()) {
            return st.top();
        }
        return -1;  // Return -1 for an empty stack (assuming all values in the stack are positive)
    }
};

int main() {
    Stack stack;

    // Check if the stack is empty
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Get the size of the stack
    cout << "Stack size: " << stack.getSize() << endl;

    // Access the top element
    cout << "Top element: " << stack.top() << endl;

    // Pop elements from the stack
    stack.pop();

    // Get the new top element
    cout << "New top element: " << stack.top() << endl;

    return 0;
}
