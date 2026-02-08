#include <iostream>
#include <stack>

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
