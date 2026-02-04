#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->ch << "      " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanCoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (int i = 0; i < chars.size(); i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    cout << "Character Huffman Code\n";
    printCodes(minHeap.top(), "");
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCoding(chars, freq);

    return 0;
}
