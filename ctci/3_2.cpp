#include <algorithm>
#include <iostream>
#include <stack>

// Solution 1: Use 2 stacks
class MinStackInt {
   private:
    std::stack<int> min_st;
    std::stack<int> st;

   public:
    int top() {
        return st.top();
    }

    void push(int x) {
        if (min_st.empty() || x <= min_st.top()) {
            min_st.push(x);
        }
        st.push(x);
    }

    void pop() {
        if (min_st.top() == st.top()) min_st.pop();
        st.pop();
    }

    int min_val() {
        return min_st.top();
    }

    void traverse() {
        std::stack<int> st_copy = st;
        while (!st_copy.empty()) {
            std::cout << st_copy.top() << " ";
            st_copy.pop();
        }
        std::cout << std::endl;
    }
};

// Solution 2: Using single stack but modified stack node
struct StackNode {
    int val;
    int min_so_far;
};

class MinStackInt2 {
   private:
    std::stack<StackNode> st;

   public:
    int top() {
        return st.top().val;
    }

    void push(int x) {
        StackNode node;

        node.min_so_far = st.empty()
                              ? x
                              : std::min(x, st.top().min_so_far);

        node.val = x;
        st.push(node);
    }

    void pop() {
        st.pop();
    }

    int min_val() {
        return st.top().min_so_far;
    }

    void traverse() {
        std::stack<StackNode> st_copy = st;
        while (!st_copy.empty()) {
            std::cout << st_copy.top().val << " ";
            st_copy.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    MinStackInt minimum_stack;

    minimum_stack.push(10);
    minimum_stack.push(20);
    minimum_stack.push(30);
    minimum_stack.push(5);

    minimum_stack.traverse();

    std::cout << minimum_stack.min_val() << std::endl;

    minimum_stack.pop();

    std::cout << minimum_stack.min_val() << std::endl;
}
