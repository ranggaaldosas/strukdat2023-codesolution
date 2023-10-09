#include <iostream>
using namespace std;

// Struktur node untuk BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan node baru ke dalam BST
Node* insertNode(Node* root, int data) {
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

// Fungsi untuk mencetak BST inorder
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int input;

    for (int i = 0; i < 10; ++i) {
        cin >> input;

        root = insertNode(root, input);
    }

    inorderTraversal(root);
    cout << endl;

    return 0;
}