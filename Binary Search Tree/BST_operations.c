#include<stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} Node;

Node* insertNode(Node *root, int val) {
    if (root == NULL) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->key = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->key) {
        root->left = insertNode(root->left, val);
    } else if (val > root->key) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

Node* searchNode(Node *root, int target) {
    if (root == NULL || root->key == target) {
        return root;
    }
    if (target < root->key) {
        return searchNode(root->left, target);
    }
    return searchNode(root->right, target);
}

Node* findMin(Node *root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (x < root->key) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->key) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int val, choice;
    while (1) {
        printf("------BINARY SEARCH TREE------\n");
        printf("\t1. Insert node\n\t2. Delete node\n\t3. Search node\n\t4. Display\n\t5. Exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data:");
                scanf("%d", &val);
                root = insertNode(root, val);
                printf("%d is inserted in BST.\n", val);
                break;
            case 2:
                if (root != NULL) {
                    printf("Enter value to delete:");
                    scanf("%d", &val);
                    root = deleteNode(root, val);
                    printf("%d is deleted from BST.\n", val);
                }
                else printf("BST is empty.\n");
                break;
            case 3:
                if (root!=NULL) {
                    printf("Enter data to search:");
                    scanf("%d", &val);
                    if (searchNode(root, val)) {
                        printf("Value %d is found.\n", val);
                    } else printf("Value is not found.\n");
                }
                else printf("BST is empty.\n");
                break;
            case 4:
                if (root != NULL) {
                    inOrder(root);
                    printf("\n");
                }
                else printf("BST is empty.\n");
                break;
            case 5:
                printf("Exited.\n");
                return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
