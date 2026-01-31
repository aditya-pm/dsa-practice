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

ListNode* append_node(int value) {
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

void print_list() {
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
    append_node(1);
    append_node(1);
    append_node(2);
    append_node(6);
    append_node(3);
    append_node(4);
    append_node(5);
    append_node(6);
    print_list();

    removeElements(1);
    print_list();

    return 0;
}
