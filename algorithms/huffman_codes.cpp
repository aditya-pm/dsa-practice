#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

int totalBits = 0;

void printCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$') {
        cout << root->ch << " : " << code << endl;
        totalBits += root->freq * code.length();
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++) {
        char c;
        int f;
        cout << "Enter character and frequency: ";
        cin >> c >> f;

        pq.push(new Node(c, f));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    cout << "\nTotal bits required: " << totalBits << endl;

    return 0;
}