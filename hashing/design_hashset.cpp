#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
   private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    vector<ListNode*> vec;
    static const int SIZE = 10007;

   public:
    MyHashSet() : vec(SIZE, nullptr) {}

    void add(int key) {
        int index = key % SIZE;
        if (vec[index] == nullptr) {
            vec[index] = new ListNode(key);
        } else {
            ListNode* temp = vec[index];
            while (temp->next != nullptr) {
                if (temp->val == key) return;  // does not check last node value
                temp = temp->next;
            }
            if (temp->val == key) return;  // check last node value
            temp->next = new ListNode(key);
        }
    }

    void remove(int key) {
        int index = key % SIZE;
        ListNode dummy(0);
        dummy.next = vec[index];
        ListNode* temp = &dummy;

        while (temp->next != nullptr) {
            if (temp->next->val == key)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }

        vec[index] = dummy.next;
    }

    bool contains(int key) {
        int index = key % SIZE;
        ListNode* temp = vec[index];
        while (temp != nullptr) {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }
};