// 155. Min Stack
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
   private:
    stack<int> st;
    stack<int> minSt;

   public:
    MinStack() {}

    void push(int val) {
        if (minSt.empty() || minSt.top() >= val) minSt.push(val);
        st.push(val);
    }

    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};