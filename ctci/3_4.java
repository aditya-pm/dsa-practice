package ctci;

import java.util.Stack;

class MyQueue {
    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    public MyQueue() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    private void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.pop());
        }
    }

    public boolean isEmpty() {
        return inStack.empty() && outStack.empty();
    }

    public void push(int x) {
        inStack.push(x);
    }

    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty!");
        }

        if (outStack.empty()) {
            transfer();
        }

        return outStack.peek();
    }

    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty!");
        }

        if (outStack.empty())
            transfer();

        return outStack.pop();
    }
}
