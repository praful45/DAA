//Lab 5.1 Huffman coding
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode* left, * right;
    HuffmanNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// Function to compare two Huffman nodes
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->freq > r->freq);
    }
};

// Traverse the Huffman tree and store Huffman codes
void encode(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Build Huffman tree and generate codes for input symbols
void buildHuffmanTree(string text) {
    unordered_map<char, unsigned> freq;
    for (char c : text) {
        freq[c]++;
    }
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* newNode = new HuffmanNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    unordered_map<char, string> huffmanCode;
    encode(pq.top(), "", huffmanCode);
    cout << "Huffman Codes are: " << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int main() {
    string text = "This is a test message";
    buildHuffmanTree(text);
    return 0;
}

