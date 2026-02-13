#include <iostream>
#include <stack>
#include <stdexcept>

class MyQueue {
   private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;

    void in_to_out() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

   public:
    bool is_empty() const {
        return in_stack.empty() && out_stack.empty();
    }

    void push(int x) {
        in_stack.push(x);
    }

    int peek() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        if (out_stack.empty()) in_to_out();
        return out_stack.top();
    }

    int pop() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        if (out_stack.empty()) in_to_out();
        int val = out_stack.top();
        out_stack.pop();
        return val;
    }
};
