#include <iostream>
using namespace std;

// Struktur node untuk BST
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan node baru ke dalam BST
Node* insertNode(Node* root, char data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Fungsi untuk mencetak BST preorder
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    string input;

    // cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);

    // Memasukkan karakter dari kalimat ke dalam BST
    for (char c : input) {
        root = insertNode(root, c);
    }

    // cout << "Traversal BST (preorder): ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}