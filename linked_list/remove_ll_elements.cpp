#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* head = nullptr;
ListNode* tail = nullptr;

ListNode* createNode(int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return newNode;
}

void printList() {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

ListNode* removeElements(int value) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        if (curr == head && curr->val == value) {
            head = curr->next;
        } else if (curr->val == value) {
            prev->next = curr->next;
        } else {
            // if no node deleted, only then update prev
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

ListNode* removeElements2(int value) {
    // unifies logic for head and other nodes, makes loop simpler.
    ListNode dummy(0);
    dummy.next = head;
    ListNode* curr = &dummy;

    while (curr->next != nullptr) {
        if (curr->next->val == value) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;  // new head (might have changed)
}

int main() {
    createNode(1);
    createNode(1);
    createNode(2);
    createNode(6);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    printList();

    removeElements(1);
    printList();

    return 0;
}
