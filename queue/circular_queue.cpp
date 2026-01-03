// 622. Design Circular Queue
#include <iostream>
using namespace std;

class MyCircularQueue {
   private:
    int* arr;
    int front;
    int rear;
    int capacity;

   public:
    MyCircularQueue(int k) {
        front = 0;
        rear = 0;
        capacity = k + 1;
        arr = new int[capacity];
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};