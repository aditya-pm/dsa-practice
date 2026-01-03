#include <iostream>
#include <queue>
using namespace std;

class MyStack {
   private:
   public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    void print() {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();
    cout << stack.q.front();
    // stack.pop();
    // stack.print();

    return 0;
}
