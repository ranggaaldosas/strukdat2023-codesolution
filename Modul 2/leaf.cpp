#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void findLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    findLeafNodes(root->left);
    findLeafNodes(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n >= 1000) {
        printf("Bang udah bang.\n");
        return 0;
    }

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        if (root == NULL) {
            root = createNode(data);
        } else {
            struct TreeNode* current = root;
            while (1) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(data);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == NULL) {
                        current->right = createNode(data);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    findLeafNodes(root);
    printf("\n");

    return 0;
}